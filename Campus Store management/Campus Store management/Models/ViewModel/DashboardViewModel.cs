namespace Campus_Store_management.Models.ViewModel
{
    public class DashboardViewModel
    {
        public List<Customer> customer { get; set; } = new List<Customer>();
        public  List<Product> product { get; set; } = new List<Product>();
      
        public DashboardViewModel()
        {
            customer.Add(new Customer { CustomerId = 1, CustomerName = "Ali", Email = "ali@example.com" });
            customer.Add(new Customer { CustomerId = 2, CustomerName = "Sara", Email = "sara@example.com" });
            product.Add(new Product { ProductId = 1, ProductName = "Laptop", Price = 80000 ,Category="Device"});
            product.Add(new Product { ProductId = 2, ProductName = "Notebook", Price = 300 ,Category ="Book"});
            product.Add(new Product { ProductId = 3, ProductName = "Headphones", Price = 4000,Category="Wireless Device" });
        }
    }
}
