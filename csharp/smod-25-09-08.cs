// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors: Diyor Haydarov[alyreniko]
//   Date: September 8, 2024
//   License: MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

class Program
{
    // 1А. Даны два целых числа А и В (А < В). Вывести в порядке возрастания все целые числа,
    // расположенные между А и В (включая сами числа А и В), а также количество N этих чисел.
    static void task1a()
    {
        int a = 5;
        int b = 10;
        int counter = 0;
        for (int i = a; i <= b; i++)
        {
            Console.Write($"{i} ");
            counter++;
        }
        Console.WriteLine($"\nN = {counter}");
    }

    // 1Б. Даны два целых числа А и В (А < В). Вывести в порядке убывания все целые числа,
    // расположенные между А и В (не включая числа А и В), а также количество N этих чисел.
    static void task1b()
    {
        int a = 5;
        int b = 10;
        int counter = 0;
        for (int i = a + 1; i < b; i++)
        {
            Console.Write($"{i} ");
            counter++;
        }
        Console.WriteLine($"\nN = {counter}");
    }

    static double task2a(double X, int N)
    {
        double result = 0;
        double term = X;
        result += term;

        for (int i = 1; i <= N; i++)
        {
            double power = Math.Pow(X, 2 * i + 1);
            long factorial = 1;

            for (int j = 1; j <= 2 * i + 1; j++)
                factorial *= j;

            double sign = i % 2 == 0 ? 1 : -1;
            term = sign * power / factorial;
            result += term;
        }
        return result;
    }

    static double task2b(double X, int N)
    {
        double result = 1;
        for (int i = 1; i <= N; i++)
        {
            double power = Math.Pow(X, 2 * i);
            long factorial = 1;

            for (int j = 1; j <= 2 * i; j++)
                factorial *= j;

            double sign = i % 2 == 0 ? 1 : -1;
            double term = sign * power / factorial;
            result += term;
        }
        return result;
    }

    static void task3a(int a, int b)
    {
        for (int i = a; i < b + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                Console.Write($"{i} ");
            }
        }
    }

    static double task3b(int N)
    {
        double sum = 0.0;
        for (int i = 1; i <= N; i++)
            sum += Math.Pow(i, N - i + 1);
        return sum;
    }

    static int ife1(int n)
    {
        if (n == 0) return 10;
        return (n > 0) ? n + 1 : n - 2;
    }

    static void ife2(int n)
    {
        if (n % 2 == 0)
        {
            Console.Write("четное ");
        }
        else
        {
            Console.Write("нечетное ");
        }

        if (n > 0 && n < 10)
        {
            Console.WriteLine("цифра");
        }
        else if (n >= 10 && n < 100)
        {
            Console.WriteLine("двузначное число");
        }
        else if (n >= 100 && n < 1000)
        {
            Console.WriteLine("трехзначное число");
        }
    }

    static int ife3(double x)
    {
        if (x < 0)
            return 0;
        int intervalStart = (int)x;
        return (intervalStart % 2 == 0) ? 1 : -1;
    }

    static double ife4(int a, double b)
    {
        switch (a)
        {
            case 1:
                return b * 0.1;
            case 2:
                return b * 1000;
            case 3:
                return b * 1;
            case 4:
                return b * 0.001;
            case 5:
                return b * 0.01;
            default:
                throw new ArgumentException("1 <= a <= 5");
        }
    }

    static string ife5(int year)
    {
        string[] colors = { "зеленый", "красный", "желтый", "белый", "черный" };
        string[] animals = { "крыса", "корова", "тигр", "заяц", "дракон", "змея",
                             "лошадь", "овца", "обезьяна", "курица", "собака", "свинья" };
        int position = (year - 1984) % 60;
        int colorIndex = position / 12;
        int animalIndex = position % 12;
        return $"{colors[colorIndex]} {animals[animalIndex]}";
    }

    static int bisector(int a, int b, int c)
    {
        double bisectorLength = Math.Sqrt(a * b * (1 - (c * c) / Math.Pow(a + b, 2)));
        return (int)Math.Round(bisectorLength);
    }

    static void Separator(int n)
    {
        Console.WriteLine($"\n---------- Task {n} ----------");
    }
    static void Main()
    {
        Separator(1);
        task1a();
        Separator(2);
        task1b();
        Separator(3);
        Console.WriteLine(task2a(3.14, 5));
        Separator(4);
        Console.WriteLine(task2b(3.14, 5));
        Separator(5);
        task3a(1, 3);
        Separator(6);
        Console.WriteLine(task3b(3));
        Separator(7);
        Console.WriteLine(ife1(5));
        Separator(8);
        ife2(333);
        Separator(9);
        Console.WriteLine(ife3(3));
        Separator(10);
        Console.WriteLine(ife4(5, 1000));
        Separator(11);
        Console.WriteLine(ife5(1984));
        Separator(12);
        Console.WriteLine(bisector(9, 18, 21));
    }
}
