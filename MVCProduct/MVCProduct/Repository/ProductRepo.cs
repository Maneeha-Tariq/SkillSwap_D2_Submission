using Microsoft.Data.SqlClient;
using Microsoft.IdentityModel.Protocols.OpenIdConnect;
using MVCProduct.Models;

namespace MVCProduct.Repository
{
    public class ProductRepo
    {
       const string connStr = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=ProductDBB;Integrated Security=True;";
       SqlConnection conn = new SqlConnection(connStr);
       private async Task<SqlCommand> OpenCon(string query)
       { 
            SqlCommand cmd = new SqlCommand(query, conn);
            await conn.OpenAsync();
            return cmd;
       }
       private async Task CloseConn()
       {
            conn.CloseAsync();
       }
       public async Task<List<Product>> getAllProducts()
       {
            string query = "SELECT * FROM PRODS";
            SqlCommand cmd = await OpenCon(query);
            SqlDataReader sr = await cmd.ExecuteReaderAsync();
            List<Product> list = new List<Product>();
            while(await sr.ReadAsync())
            {
                Product p = new Product();
                p.ProductName = sr["ProductName"].ToString();
                p.price = Convert.ToInt32(sr["price"]);
                list.Add(p);
            }
            await CloseConn();
            return list;
       } 
       public async Task AddProduct(Product prod)
       {
            string query = "INSERT INTO PRODS (ProductName, price) VALUES (@name, @price)";
            SqlCommand cmd = await OpenCon(query);
            cmd.Parameters.AddWithValue("@name", prod.ProductName);
            cmd.Parameters.AddWithValue("@price", prod.price);
            await cmd.ExecuteNonQueryAsync();
            await CloseConn();
        }
    }
}
