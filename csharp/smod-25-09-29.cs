// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors:        Diyor Haydarov [alyreniko]
//   Date:           September 29, 2025
//   License:        MIT License
// ╚═════════════════════════════════════════════════════════════════════════════╝
class Node
{
    public int Data;
    public Node? Left;
    public Node? Right;
    public Node? Parent;

    public Node(int data, Node? parent = null)
    {
        Data = data;
        Left = null;
        Right = null;
        Parent = parent;
    }

    public void Dump(string indent = "")
    {
        Console.WriteLine($"{indent}{Data} => {{ Data = {Data}, Left = {Left?.Data}, Right = {Right?.Data}, Parent = {Parent?.Data} }}");
        Left?.Dump(indent + "  ");
        Right?.Dump(indent + "  ");
    }
}

class Program
{
    // 1. Описать рекурсивную функцию DigitSum(K) целого типа, которая находит сумму цифр целого числа K, не используя оператор цикла.
    static int DigitSum(int K)
    {
        if (K == 0)
            return 0;
        return K % 10 + DigitSum(K / 10);
    }

    // 2. Описать рекурсивную функцию Palindrome(S) логического типа, возвращающую True, если строка S является палиндромом (т. е. читается одинаково слева направо и справа налево), и False в противном случае. Оператор цикла в теле функции не использовать.
    static bool Palindrome(string S)
    {
        if (S.Length <= 1)
            return true;
        if (S[0] != S[S.Length - 1])
            return false;
        return Palindrome(S.Substring(1, S.Length - 2));
    }

    // 3. Описать процедуру InvDigits(K), меняющую порядок следования цифр целого положительного числа K на обратный (K — параметр целого типа, являющийся одновременно входным и выходным).
    static int InvDigits(int K, int reversed = 0)
    {
        if (K == 0)
            return reversed;
        return InvDigits(K / 10, reversed * 10 + K % 10);
    }

    // 1. Дано число N (> 0) и набор из N чисел. Создать дерево из N вершин, в котором каждая вершина (кроме корня) является правой дочерней вершиной. Каждой создаваемой вершине присваивать очередное значение из исходного набора.
    static void TreeTask1(int[] numbers)
    {
        Node root = new Node(numbers[0]);
        Node current = root;

        for (int i = 1; i < numbers.Length; i++)
        {
            Node newNode = new Node(numbers[i], current);
            current.Right = newNode;
            current = newNode;
        }
        root.Dump();
    }

    // 2. Дано число N (> 0) и набор из N чисел. Создать дерево из N вершин, в котором каждая внутренняя вершина имеет только одну дочернюю вершину, причем если значение вершины является нечетным, то она имеет левую дочернюю вершину, а если четным, то правую. Каждой создаваемой вершине присваивать очередное значение из исходного набора.
    static void TreeTask2(int[] numbers)
    {
        Node root = new Node(numbers[0]);
        Node current = root;

        for (int i = 1; i < numbers.Length; i++)
        {
            Node newNode = new Node(numbers[i], current);
            if (current.Data % 2 == 0)
            {
                current.Right = newNode;
            }
            else
            {
                current.Left = newNode;
            }
            current = newNode;
        }
        root.Dump();
    }

    // 3. Дано число N (> 0). Создать дерево, корень которого имеет значение N, а вершины обладают следующими свойствами: вершина с четным значением K имеет левую дочернюю вершину со значением K/2 и не имеет правой дочерней вершины; вершина со значением 1 является листом; вершина с любым другим нечетным значением K имеет две дочерние вершины: левую со значением K/2 и правую со значением K – K/2 (символ «/» обозначает операцию деления нацело).
    static void TreeTask3(int n)
    {
        Node root = new Node(n);

        void Build(Node current)
        {
            if (current.Data == 1) return;

            int k = current.Data;
            if (k % 2 == 0)
            {
                current.Left = new Node(k / 2, current);
                Build(current.Left);
            }
            else
            {
                current.Left = new Node(k / 2, current);
                current.Right = new Node(k - k / 2, current);
                Build(current.Left);
                Build(current.Right);
            }
        }

        Build(root);
        root.Dump();
    }

    static void Separator(int n)
    {
        Console.WriteLine($"\n---------- Task {n} ----------");
    }

    static void Main(string[] args)
    {
        Separator(1);
        int n = 12345;
        Console.WriteLine($"input: {n}\noutput: {DigitSum(n)}");

        Separator(2);
        string str = "racecar";
        Console.WriteLine($"input: {str}\noutput: {Palindrome(str)}");

        Separator(3);
        Console.WriteLine($"input: {n}\noutput: {InvDigits(n)}");

        Separator(4);
        int[] arr = { 1, 2, 3, 4, 5 };
        Console.WriteLine("input: [" + string.Join(", ", arr) + "]\noutput:");
        TreeTask1(arr);

        Separator(5);
        Console.WriteLine("input: [" + string.Join(", ", arr) + "]\noutput:");
        TreeTask2(arr);

        Separator(6);
        Console.WriteLine("input: 7\noutput:");
        TreeTask3(7);
    }
}
