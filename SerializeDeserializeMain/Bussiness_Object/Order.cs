using System;
using System.Collections.Generic;
using System.Text;

namespace Bussiness_Object
{
    public class Order
    {
       public int OrderId { get; set; }
       public string? CustomerName { get; set; }
       public string? OrderDate { get; set; }
       public string? ShippingAddress { get; set; }
       public List<Product> Products { get; set; }
    }
}



