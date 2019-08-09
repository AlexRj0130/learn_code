using System;

namespace learn_csharp
{
    class Program
    {

        static void ThrowException()
        {
            throw new ArgumentNullException();
        }

        static void CatchExceptionNotThrowAgain()
        {
            try
            {
                ThrowException();
            }
            catch (Exception e)
            {
                Console.WriteLine("{0} Exception caught", e);
            }
        }

        static void Main(string[] args)
        {
            // try
            // {
            //     ThrowException();
            // }
            // catch (Exception e)
            // {
            //     Console.WriteLine("{0} Exception caught", e);
            // }
            try
            {
                CatchExceptionNotThrowAgain();
            }
            catch (Exception e)
            {
                Console.WriteLine("{0} Inner Exception caught", e);
            }

            Console.WriteLine("Hello World!");
        }
    }
}
