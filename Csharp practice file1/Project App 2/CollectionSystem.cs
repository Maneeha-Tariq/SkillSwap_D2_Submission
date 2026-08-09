using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Project_App_2
{
    internal class CollectionSystem
    {
        internal void ArrayList()
        {
            ArrayList l = new ArrayList();
            l.Add(34);
            l.Add("Maneeha");
            l.Add(3.456);
            l.Add(true);
            l.Add('r');
            //l.Insert(l.Count-1, "Aliza");
            //remove by value
            l.Remove(34);
            //remove by index
            l.RemoveAt(3);
            //Console.WriteLine("-----------------");
            //// Enumeration
            //Console.WriteLine("Display using for each loop");
            //foreach(Object o in l)
            //{
            //    Console.WriteLine(o);
            //}
            //Console.WriteLine("-----------------");
            //Console.WriteLine("Display using simple loop");
            //for(int i=0;i<l.Count;i++)
            //{
            //    Console.WriteLine(l[i]);
            //}
            //Console.WriteLine("-----------------");
            //Console.WriteLine("Index of Aliza = {0}",l.IndexOf("Aliza"));
            //if(l.Contains("Maneeha"))
            //{
            //    Console.WriteLine("Present");
            //}
            //else
            //{
            //    Console.WriteLine("Not Present");
            //}
            // this merge two collection objects
            ArrayList l1 = new ArrayList();
            l1.Add(78);
            l1.Add("aliza");
            l1.Add('i');
            l.AddRange(l1);
            foreach(object o in l)
            {
                Console.WriteLine(o);
            }
        }
        internal void HashTable()
        {
            Hashtable ht = new Hashtable();
            ht.Add(1, "ID");
            ht.Add("Name", "Maneeha");
            ht.Add("Rno", "BSEF24M046");
            ht.Add("fee", 1000);
            ht.Add(7, 'y');
            ht.Remove("Name");
            if(ht.ContainsKey("Rno"))
            {
                object o = ht["Rno"];
                Console.WriteLine("{0} is Present",o);
            }
            else
            {
                Console.WriteLine("Not Found");
            }

            if (ht.ContainsValue(1000))
            {
                Console.WriteLine("Found");
            }
            else
            {
                Console.WriteLine("Not Found");
            }
            Console.WriteLine("-----------------");
            //ht.Keys returns all keys and ht.Value returns all values
            foreach (object key in ht.Keys)
            {
                Console.WriteLine(key);
            }
            Console.WriteLine("-----------------");
            foreach (object value in ht.Values)
            {
                Console.WriteLine(value);
            }
            Console.WriteLine("-----------------");
            foreach (DictionaryEntry item in ht)
            {
                 Console.Write($"Key = {item.Key}\tValue = {item.Value}");
                 Console.WriteLine();
            }

        }
        internal void SortedList()
        {
            SortedList<string,object> ht = new SortedList<string,object>();
            ht.Add("ID",1);
            ht.Add("Name", "Maneeha");
            ht.Add("Rno", "BSEF24M046");
            ht.Add("fee", 1000);
            ht.Add("y",7);
            ht.Remove("Name");
            //if (ht.ContainsKey("Rno"))
            //{
            //    object o = ht["Rno"];
            //    Console.WriteLine("{0} is Present", o);
            //}
            //else
            //{
            //    Console.WriteLine("Not Found");
            //}

            //if (ht.ContainsValue(1000))
            //{
            //    Console.WriteLine("Found");
            //}
            //else
            //{
            //    Console.WriteLine("Not Found");
            //}
            //Console.WriteLine("-----------------");
            ////ht.Keys returns all keys and ht.Value returns all values
            //foreach (object key in ht.Keys)
            //{
            //    Console.WriteLine(key);
            //}
            //Console.WriteLine("-----------------");
            //foreach (object value in ht.Values)
            //{
            //    Console.WriteLine(value);
            //}
            //Console.WriteLine("-----------------");
            //foreach (KeyValuePair<string,object> item in ht)
            //{
            //    Console.Write($"Key = {item.Key}\tValue = {item.Value}");
            //    Console.WriteLine();
            //}
            // with for loop
            for(int i=0;i<ht.Count;i++)
            {
                Console.WriteLine($"Key: {ht.GetKeyAtIndex(i)}  Value: {ht.GetValueAtIndex(i)}");
            }

        }

        internal void sortedListNonGeneric()
        {
            SortedList sorted = new SortedList();
            sorted.Add("Three", 3);
            sorted.Add("Nine", 9);
            sorted.Add("One", 1);
            sorted.Add("Eleven", 11);
            sorted.Remove("One");
            foreach (DictionaryEntry item in sorted)
            {
                Console.WriteLine($"Key: {item.Key}  Value: {item.Value}");
            }
            Console.WriteLine("After remove at 2");
            sorted.RemoveAt(2);
            //contain and containkey are exactly the same both takes the key as a parameter
            bool result = sorted.Contains("one");
            bool result1 = sorted.ContainsKey("one");

            //// simple for loop
            //for (int i=0;i<sorted.Count;i++)
            //{
            //    Console.WriteLine($"Key: {sorted.GetKey(i)}  Value: {sorted.GetByIndex(i)}");
            //}
            // foreachloop
            foreach(DictionaryEntry item in sorted)
            {
                Console.WriteLine($"Key: {item.Key}  Value: {item.Value}");
            }
        }
        // same as array list but list in generic type safe
        internal void ListGeneric()
        {
            // direct initialization work like add function internally
            List<int> list = new List<int>() { 1000, 2000, 3000 };
            for(int i=0;i<list.Count;i++)
            {
                Console.Write($"{list[i]} ");
            }
            Console.WriteLine();
            List<object> list1 = new List<object>();
            list1.Add(1);
            list1.Add("maniha");
            foreach(object item in list1)
            {
                Console.Write($"{item}  ");
            }
        }
        // hashtable is same as in non generic
        internal void DictionaryGeneric()
        {
            Dictionary<string, int> d = new Dictionary<string, int>()
            {
                {"Maneeha",1 },{"Aliza",2}
            };
            foreach (KeyValuePair<string, int> item in d)
            {
                Console.WriteLine($"{item.Key} : {item.Value}");
            }

            Dictionary<int, string> de = new Dictionary<int, string>();
            de.Add(1, "Maneeha");
            de.Add(2, "Khadija");
            de.Add(3, "Muneeba");
            foreach(KeyValuePair<int, string> item in de)
            {
                Console.WriteLine($"{item.Key} : {item.Value}");
            }
        }
        // hashset store unique values if yu write duplicate then it does not consider it
        // print that value only once unlike linst and arrray list that also accept duplicates
        internal void hashsetGeneric()
        {
            //HashSet<int> hs = new HashSet<int>();
            //// output 1 2
            //hs.Add(1);
            //hs.Add(2);
            //hs.Add(1);

            //foreach(int item in hs)
            //{
            //    Console.WriteLine($"{item}");   
            //}

            HashSet<string> hs1 = new HashSet<string>();
            hs1.Add("maniha");
            hs1.Add("khadija");
            hs1.Add("aya");
            hs1.Add("aya");
            foreach (string item in hs1)
            {
                Console.WriteLine($"{item}");
            }
        }
        internal void stack()
        {
            Stack<int> stk = new Stack<int>();  
            stk.Push(1);
            stk.Push(2);
            stk.Push(8);
            //stk.Pop();
            
          
            //foreach(int item in stk)
            //{
            //    Console.Write($"{item} ");
            //}
            while(stk.Count > 0) 
            {
                Console.Write($"{stk.Peek()} ");
                stk.Pop();
            }
            
        }
        internal void queue()
        {
            Queue<string> stk = new Queue<string>();
            stk.Enqueue("maneeha");
            stk.Enqueue("alina");
           //while(stk.Count > 0) 
           // {    
           //     Console.WriteLine($"{stk.Peek()}");
           //     stk.Dequeue();
           // }
            foreach (string item in stk)
            {
                Console.WriteLine(item);
            }
        }
        internal void linkedlist()
        {
            LinkedList<int> ll = new LinkedList<int>();
            ll.AddFirst(1);
            ll.AddLast(2);
            LinkedListNode<int> node = ll.Find(1);
            ll.AddAfter(node, 4);
            LinkedListNode<int> node1 = ll.Find(4);
            ll.AddBefore(node1, 9);
            foreach(int item in ll)
            {
                Console.WriteLine(item);
            }
        }


    }
}
