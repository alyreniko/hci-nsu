// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors: Diyor Haydarov[alyreniko]
//   Date: September 22, 2024
//   License: MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝

class Program
{
    static void CreateBinaryFile(string filePath, int count, bool isSquareMatrix = false)
    {
        Random rnd = new Random();
        using (var bw = new BinaryWriter(File.Create(filePath)))
        {
            int outer = count;
            int inner = isSquareMatrix ? count : 1;

            for (int i = 0; i < outer; i++)
            {
                for (int j = 0; j < inner; j++)
                {
                    bw.Write(Math.Round(rnd.NextDouble() * (100 - 1) + 1, 2));
                }
            }
        }
        Console.WriteLine($"created binary file '{filePath}':");
        PrintBinaryFile(filePath, isSquareMatrix);
    }

    static void PrintBinaryFile(string filePath, bool isSquareMatrix = false)
    {
        Console.WriteLine($"content in '{filePath}':");
        using (var br = new BinaryReader(File.Open(filePath, FileMode.Open)))
        {
            long fileSize = new FileInfo(filePath).Length;
            int totalCount = (int)(fileSize / sizeof(double));

            int rows = isSquareMatrix ? (int)Math.Sqrt(totalCount) : totalCount;
            int cols = isSquareMatrix ? (int)Math.Sqrt(totalCount) : 1;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write($"[{br.ReadDouble()}] ");
                }
                Console.WriteLine();
            }
        }
    }

    // 1. Дан файл вещественных чисел, содержащий элементы квадратной матрицы (по строкам). Создать новый файл, содержащий элементы матрицы, транспонированной к исходной.
    static void binaryTask1(string inFile, string outFile)
    {
        CreateBinaryFile(inFile, 3, isSquareMatrix: true);
        using var br = new BinaryReader(File.OpenRead(inFile));
        long cnt = br.BaseStream.Length / sizeof(double);
        int n = (int)Math.Sqrt(cnt);
        double[] a = new double[cnt];
        for (int i = 0; i < cnt; i++) a[i] = br.ReadDouble();
        using (var bw = new BinaryWriter(File.Create(outFile)))
        {
            for (int c = 0; c < n; c++)
                for (int r = 0; r < n; r++)
                    bw.Write(a[r * n + c]);
        }
        Console.WriteLine("transposed matrix:");
        PrintBinaryFile(outFile, isSquareMatrix: true);
    }

    // 2. Дано целое число N (≤ 4) и N файлов целых чисел с именами S1, ..., SN. Объединить их содержимое в новом файле-архиве с именем S0, последовательно записывая в него следующие данные: размер (число элементов) первого исходного файла и все элементы этого файла, размер второго исходного файла и все его элементы, ..., размер N-го исходного файла и все его элементы.
    static void binaryTask2(string[] inFiles, string outFile)
    {
        Random rnd = new Random();
        foreach (string file in inFiles)
        {
            CreateBinaryFile(file, rnd.Next(1, 5));
        }
        using (BinaryWriter bw = new BinaryWriter(File.Create(outFile)))
        {
            foreach (string file in inFiles)
            {
                using (BinaryReader br = new BinaryReader(File.OpenRead(file)))
                {
                    long count = br.BaseStream.Length / sizeof(double);
                    bw.Write((double)count);
                    for (int i = 0; i < count; i++)
                        bw.Write(br.ReadDouble());
                }
            }
        }
        PrintBinaryFile(outFile);
    }

    // 3. Дано целое число N (>0) и файл-архив целых чисел, содержащий данные из нескольких файлов в формате, описанном в задании №2. Восстановить из файла-архива файл с номером N и сохранить его под именем S. Если файл-архив содержит данные из менее чем N файлов, то оставить результирующий файл пустым.
    static void binaryTask3(string inFile)
    {
        PrintBinaryFile(inFile);
        using (BinaryReader br = new BinaryReader(File.Open(inFile, FileMode.Open)))
        {
            long allCount = br.BaseStream.Length / sizeof(double);
            int iterCont = 0;
            int fileId = 1;
            for (int i = 0; i < allCount; i++)
            {
                iterCont = (int)br.ReadDouble();
                using (var bw = new BinaryWriter(File.Create($"S{fileId}")))
                {
                    for (int j = 0; j < iterCont; j++)
                    {
                        bw.Write(br.ReadDouble());
                    }
                }
                PrintBinaryFile($"S{fileId}");
                i += iterCont;
                fileId++;
            }
        }
    }

    // 4. Даны два файла одного и того же типа. Добавить к первому файлу содержимое второго файла, а ко второму файлу — содержимое первого.
    static void binaryTask4(string inFile1, string inFile2)
    {
        Console.WriteLine($"before:");
        PrintBinaryFile(inFile1);
        PrintBinaryFile(inFile2);

        long br1Length, br2Length;

        using (BinaryReader file1 = new BinaryReader(File.Open(inFile1, FileMode.Open, FileAccess.Read, FileShare.Read)))
        using (BinaryReader br2 = new BinaryReader(File.Open(inFile2, FileMode.Open, FileAccess.Read, FileShare.Read)))
        {
            br1Length = file1.BaseStream.Length / sizeof(double);
            br2Length = br2.BaseStream.Length / sizeof(double);

            using (var bw1 = new BinaryWriter(File.Open(inFile1, FileMode.Append, FileAccess.Write, FileShare.Read)))
                for (int i = 0; i < br2Length; i++)
                    bw1.Write(br2.ReadDouble());

            file1.BaseStream.Seek(0, SeekOrigin.Begin);

            using (var bw2 = new BinaryWriter(File.Open(inFile2, FileMode.Append, FileAccess.Write, FileShare.Read)))
                for (int i = 0; i < br1Length; i++)
                    bw2.Write(file1.ReadDouble());
        }

        Console.WriteLine($"after:");
        PrintBinaryFile(inFile1);
        PrintBinaryFile(inFile2);
    }

    // 1. Дано имя файла и целое число N (0 < N < 27). Создать текстовый файл с указанным именем и записать в него N строк длины N, строка с номером K (K = 1, ..., N) должна содержать K начальных прописных (т. е. заглавных) латинских букв, дополненных справа символами «*» (звездочка). Например, для N = 4 файл должен содержать строки «A***», «AB**», «ABC*», «ABCD».
    static void textFileTask1(string fileName, int n)
    {
        if (!(n > 0 && n < 27))
        {
            Console.WriteLine("invalid input 'n'");
            return;
        }
        using (StreamWriter writer = new StreamWriter(fileName))
        {
            char[] letter = new char[n];
            Array.Fill(letter, '*');
            for (int i = 0; i < n; i++)
            {
                letter[i] = (char)('A' + i);
                writer.WriteLine(letter);
            }
        }
        Console.WriteLine($"file '{fileName}' created successfully!");
    }

    // 2. Дана строка S и текстовый файл.Заменить в файле все пустые строки на строку S.
    static void textFileTask2(string fileName, string s)
    {
        string tempFile = Path.GetTempFileName();

        using (var reader = new StreamReader(fileName))
        using (var writer = new StreamWriter(tempFile))
        {
            string? line;
            while ((line = reader.ReadLine()) != null)
                writer.WriteLine(string.IsNullOrWhiteSpace(line) ? s : line);
        }

        File.Delete(fileName);
        File.Move(tempFile, fileName);

        Console.WriteLine($"file '{fileName}' updated successfully!");
    }

    // 3. Даны вещественные числа A, B и целое число N. Создать текстовый файл, содержащий таблицу значений функции (x)¹/² на промежутке [A, B] с шагом (B – A)/N.Таблица состоит из двух столбцов: с аргументами x(10 позиций, из них 4 под дробную часть) и со значениями(x)¹/² (15 позиций, из них 8 под дробную часть). Столбцы выравниваются по правому краю.
    static void textFileTask3(string fileName, double a, double b, int n)
    {
        string tempFile = Path.GetTempFileName();

        using (var writer = new StreamWriter(tempFile))
        {
            double step = (b - a) / n;
            for (int i = 0; i <= n; i++)
            {
                double x = a + i * step;
                double y = Math.Sqrt(x);

                writer.WriteLine("{0,10:F4}{1,15:F8}", x, y);
            }
        }

        if (File.Exists(fileName))
            File.Delete(fileName);

        File.Move(tempFile, fileName);

        Console.WriteLine($"file '{fileName}' created successfully!");
    }

    static void Separator(int n)
    {
        Console.WriteLine($"\n---------- Task {n} ----------");
    }

    static void Main(string[] args)
    {
        Separator(1);
        binaryTask1("m1_in", "m1_out");
        Separator(2);
        binaryTask2(new string[] { "S1", "S2", "S3" }, "S0");
        Separator(3);
        binaryTask3("S0");
        Separator(4);
        binaryTask4("S1", "S2");
        Separator(5);
        textFileTask1("textTast1.txt", 26);
        Separator(6);
        textFileTask2("textTask2.txt", "<= it was empty here !");
        Separator(7);
        textFileTask3("textTask3.txt", 2.5, 3.5, 5);
    }
}
