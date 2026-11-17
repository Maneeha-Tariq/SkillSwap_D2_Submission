using Business_Object;

using Microsoft.Data.SqlClient;
using System.Data;
using System.Text.Json;
using System.Xml.Linq;
using static System.Net.Mime.MediaTypeNames;
using static System.Runtime.InteropServices.JavaScript.JSType;
namespace ProductMain
{
    public class ProductDal
    {
       
        const string connectionString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=ProductDb;Integrated Security=True";
        SqlConnection conn = new SqlConnection(connectionString);
        SqlDataAdapter adptr;
        SqlCommandBuilder builder;
        private SqlCommand helperConnOpen(string query)
        {
            SqlCommand cmd = new SqlCommand(query, conn);
            conn.Open();
            return cmd;
        }
        private void helperConnClose()
        {
            conn.Close();
        }

        public void AddProduct(Product product)
        { 
            string query = $"INSERT INTO PRODUCT(Name,Price,QuantityInStock,Catagory) VALUES('{product.Name}',{product.Price},{product.QuantityInStock},'{product.Category}')";
            SqlCommand cmd = helperConnOpen(query);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public List<Product> GetAllProducts()
        {
            string query = $"SELECT * FROM PRODUCT";

            SqlCommand cmd = helperConnOpen(query);
           
            SqlDataReader s = cmd.ExecuteReader();
            List<Product> list = new List<Product>();
            while (s.Read())
            {
                Product p = new Product();
                p.ProductId = Convert.ToInt32(s["ProductId"]);
                p.Price= Convert.ToDecimal(s["Price"]);
                p.QuantityInStock = Convert.ToInt32(s["QuantityInStock"]);
                p.Category = Convert.ToString(s["Catagory"]);
                p.Name = Convert.ToString(s["Name"]);
                

                list.Add(p);
            }
            helperConnClose();

            return list;
        }
        public void GetProductById(int productId)
        {
            string query = $"SELECT Name,Price,QuantityInStock,Catagory FROM PRODUCT where ProductId = {productId}";

            SqlCommand cmd = helperConnOpen(query);
           
            SqlDataReader s = cmd.ExecuteReader();
            if (s.Read())
            {
                Console.WriteLine($"Name: {s["Name"]}, Price: {s["Price"]},Quantity: {s["QuantityInStock"]}, Catagory: {s["Catagory"]}");
            }
            else
            {
                Console.WriteLine("Not found");
            }
            helperConnClose();
        }
        public void updateProduct(Product product)
        {
            string query = $"Update PRODUCT SET Name = {product.Name}, Quantity = {product.QuantityInStock}, Catagory = {product.Category}, Price = {product.Price} WHERE PRODUCTID = {product.ProductId}";
            SqlCommand cmd = helperConnOpen(query);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public void deleteProduct(int productId)
        {
            string query = $"Delete from Product where productid = {productId}";
            SqlCommand cmd = helperConnOpen(query);
            cmd.ExecuteNonQuery();
            helperConnClose();
        }
        public List<Product> SearchProductsByName(string keyword)
        {
            string query = "SELECT * FROM PRODUCT WHERE NAME LIKE @key";
            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@key", "%" + keyword + "%");
            SqlDataAdapter adptr = new SqlDataAdapter();
            adptr.SelectCommand = cmd;
           
            DataTable dt = new DataTable();
            adptr.Fill(dt);
            List<Product> list = new List<Product>();
            foreach (DataRow dr in dt.Rows)
            {
                Product p = new Product();
                p.Name = dr["Name"].ToString();
                p.QuantityInStock = Convert.ToInt32(dr["QuantityInStock"]);
                p.Category = dr["Catagory"].ToString();
                p.Price = Convert.ToInt32(dr["Price"]);
                list.Add(p);
            }
            return list;
        }
        public void ExportProductsToJson(string filePath)
        {
           List<Product> list =  GetAllProducts();
          
           StreamWriter sw = new StreamWriter(filePath);
           
           string serStr = JsonSerializer.Serialize(list);
           sw.WriteLine(serStr);
            
           sw.Close();
        }
       public void ImportProductsFromJson(string filePath)
        {
            FileStream fs = new FileStream(filePath, FileMode.Open);
            StreamReader sr = new StreamReader(fs);
           
            string line = sr.ReadToEnd();
           
            List<Product> b = JsonSerializer.Deserialize<List<Product>>(line);
            foreach (Product p1 in b)
            {
                AddProduct(p1);
            }
            sr.Close();
            
        }
        public DataTable LoadProductsTable()
        {
            string query = "SELECT* FROM PRODUCT";
            SqlCommand cmd = new SqlCommand(query, conn);
            adptr = new SqlDataAdapter();
            adptr.SelectCommand = cmd;
            builder = new SqlCommandBuilder(adptr);
            DataTable dt = new DataTable();
            adptr.Fill(dt);
            return dt;
        }
        public void UpdatePriceInTable(DataTable table, SqlDataAdapter adapter, int productId, decimal newPrice)
        {
            DataRow[] search = table.Select("ProductId = " + productId);
            if (search.Length > 0)
            {
                search[0]["Price"] = newPrice;
                
            }
            string updateQuery = $"UPDATE PRODUCT SET Price = @pr WHERE ProductId = @id";
            adapter.UpdateCommand = new SqlCommand(updateQuery, conn);
            adapter.UpdateCommand.Parameters.Add("@id", SqlDbType.Int, 0, "ProductId");
            adapter.UpdateCommand.Parameters.Add("@pr", SqlDbType.Int, 0, "Price");
            adapter.Update(table);

        }

    }    
    
}
