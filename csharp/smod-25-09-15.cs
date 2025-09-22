// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors: Diyor Haydarov[alyreniko]
//   Date: September 15, 2024
//   License: MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

class Program
{
    static void printArray(int[] arr, int visibleLength)
    {
        Console.Write("[ ");
        for (int i = 0; i < visibleLength; i++)
            Console.Write($"{arr[i]}, ");
        Console.Write("]");
        Console.WriteLine();
    }

    static int[] sortask1(int[] arr)
    {
        int n = arr.Length;
        int b = n;
        for (int c = 0; b > 2; c++)
        {
            Console.WriteLine($"проход {c + 1}:");
            for (int i = 0; i < b - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    (arr[i], arr[i + 1]) = (arr[i + 1], arr[i]);
                }
                Console.Write($" {arr[i]};");
            }
            Console.WriteLine("");
            b--;
        }
        Console.WriteLine("sorted:");
        printArray(arr, n);
        return arr;
    }

    static int[] sortask2(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++)
        {
            Console.WriteLine($"проход {i + 1}:");
            int maxIndex = 0;
            for (int j = 1; j < n - i; j++)
                if (arr[j] > arr[maxIndex])
                    maxIndex = j;

            if (maxIndex != n - i - 1)
                (arr[maxIndex], arr[n - i - 1]) = (arr[n - i - 1], arr[maxIndex]);

            printArray(arr, n);
        }
        Console.WriteLine("sorted:");
        printArray(arr, n);
        return arr;
    }

    static int[] sortask3(int[] arr)
    {
        int n = arr.Length;
        int[] extendedArr = new int[n + 1];

        for (int i = 0; i < n; i++)
            extendedArr[i + 1] = arr[i];

        for (int i = 2; i <= n; i++)
        {
            Console.WriteLine($"elem: {i}:");
            extendedArr[0] = extendedArr[i];
            int j = i - 1;
            while (extendedArr[j] > extendedArr[0])
            {
                extendedArr[j + 1] = extendedArr[j];
                j--;
            }

            extendedArr[j + 1] = extendedArr[0];

            for (int k = 0; k < n; k++)
                arr[k] = extendedArr[k + 1];

            printArray(arr, n);
        }

        Console.WriteLine("sorted:");
        printArray(arr, n);
        return arr;
    }

    static int[] mastask1(int[] arr)
    {
        int n = arr.Length;
        int oddCount = (n + 1) / 2;
        int new_n = n + oddCount * 2;
        int[] new_arr = new int[new_n];
        int index_in_new_arr = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 1 + (2 * (i % 2)); j++)
            {
                new_arr[index_in_new_arr] = arr[i];
                index_in_new_arr++;
            }
        }
        printArray(new_arr, index_in_new_arr);
        return new_arr;
    }

    static double[] Smooth(double[] arr)
    {
        int n = arr.Length;
        double[] result = new double[arr.Length];
        Array.Copy(arr, result, arr.Length);
        double sum = 0;

        for (int l = 0; l < n; l++)
        {
            Console.WriteLine($"сглаживание {l + 1}:");
            for (int k = 1; k < arr.Length; k++)
            {
                for (int i = 0; i <= k; i++)
                {
                    sum += result[i];
                }
                result[k] = sum / (k + 1);
                sum = 0;
            }

            for (int i = 0; i < result.Length; i++)
                Console.Write($" {result[i]:F2},");
            Console.WriteLine();
        }

        return result;
    }

    static void Hill(double[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n / 2; i++)
        {
            int minIndex = i;
            for (int j = i; j < n - i; j++)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            double temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            minIndex = i + 1;
            for (int j = i + 1; j < n - i; j++)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            temp = arr[n - i - 1];
            arr[n - i - 1] = arr[minIndex];
            arr[minIndex] = temp;
        }
        for (int i = 0; i < n; i++)
            Console.Write($" {arr[i]:F2},");
        Console.WriteLine();
    }

    static int[] SortIndex(double[] arr)
    {
        int[] idx_arr = new int[arr.Length];
        int n = arr.Length;

        for (int i = 0; i < n; i++)
            idx_arr[i] = i;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[idx_arr[i]] > arr[idx_arr[j]])
                {
                    int temp = idx_arr[i];
                    idx_arr[i] = idx_arr[j];
                    idx_arr[j] = temp;
                }
            }
        }
        return idx_arr;
    }

    static void Separator(int n)
    {
        Console.WriteLine($"\n---------- Task {n} ----------");
    }

    static void Main()
    {
        Separator(1);
        sortask1(new int[] { 3, 1, 2, 5, 4 });

        Separator(2);
        sortask2(new int[] { 3, 1, 2, 5, 4 });

        Separator(3);
        sortask3(new int[] { 3, 1, 2, 5, 4 });

        Separator(4);
        mastask1(new int[] { 1, 2, 3, 4, 5 });

        Separator(5);
        Smooth(new double[] { 3.14, 2.71, 4.14, 4.71, 5.14 });

        Separator(6);
        Hill(new double[] { 3.14, 2.71, 4.14, 4.71, 5.14 });

        Separator(7);
        double[] arr = { 3.14, 2.71, 4.14, 4.71, 5.14 };
        int[] idx_arr = SortIndex(arr);

        Console.Write("idx_arr:\n");
        foreach (var idx in idx_arr)
            Console.Write($" {idx},");
        Console.WriteLine();

        Console.Write("sorted:\n");
        foreach (var idx in idx_arr)
            Console.Write($" {arr[idx]},");
        Console.WriteLine();
    }
}
