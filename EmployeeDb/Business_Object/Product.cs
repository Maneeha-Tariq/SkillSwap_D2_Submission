using System.Xml.Linq;

namespace Business_Object
{
    public class Product
    {
        public int ProductId { get; set; }
        public string? Name { get; set; }
        public decimal Price { get; set; }
        public int QuantityInStock { get; set; }
        public string? Category { get; set; }

        public Product()
        {
            ProductId = 1;
            Name = null;
            Price = 0;
            QuantityInStock = 0;
            Category = null;
        }
        public Product(int id ,string name,decimal p,int quant,string catog)
        {
            ProductId = id;
            Name = name;
            Price = p;
            QuantityInStock = quant;
            Category = catog;

        }

    }



}
