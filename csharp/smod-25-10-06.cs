// ╔═════════════════════════════════════════════════════════════════════════════╗
//   Authors:        Diyor Haydarov [alyreniko]
//   Date:           October 6, 2025
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
    // 1. Дана строка Ѕ, содержащая описание непустого дерева в следующем формате:
    // <дерево> ::= <пусто> | <вершина>(<левое поддерево>, <правое поддерево>)
    // <вершина> ::= <цифра>
    // Например, «4(2(,),6(,7(3(,),)))» (пробелы отсутствуют). Создать дерево по описанию, приведенному в Ѕ.
    static Node? TreeTask1(string input)
    {
        int pos = 0;
        Node? root = ParseNode(input, ref pos, null);
        return root;
    }

    static Node? ParseNode(string s, ref int pos, Node? parent)
    {
        if (pos >= s.Length || s[pos] == ',' || s[pos] == ')')
            return null;

        int value = 0;
        while (pos < s.Length && char.IsDigit(s[pos]))
        {
            value = value * 10 + (s[pos] - '0');
            pos++;
        }

        Node node = new Node(value, parent);

        if (pos >= s.Length || s[pos] != '(')
            return node;
        pos++;
        node.Left = ParseNode(s, ref pos, node);
        pos++;
        node.Right = ParseNode(s, ref pos, node);
        pos++;
        return node;
    }

    // 2. Дана строка Ѕ(пробелы отсутствуют), содержащая описание числового выражения в следующем формате:
    // <выражение> ::= <цифра> | (<выражение><знак><выражение>)
    // <знак> ::= +|-|*
    // Создать дерево разбора выражения: каждая внутренняя вершина должна соответствовать одной из трех возможных арифметических операций и иметь значение 1 для операции сложения, 2 для операции вычитания и 3 для операции умножения; левое и правое дочерние поддеревья любой внутренней вершины-операции должны соответствовать выражениям слева и справа от знака операции; листьями полученного дерева должны быть выражения-цифры.
    static Node? TreeTask2(string input)
    {
        int pos = 0;
        Node? root = ParseExpr(input, ref pos, null);
        return root;
    }

    static Node ParseExpr(string s, ref int pos, Node? parent)
    {
        char c = s[pos];

        if (char.IsDigit(c))
        {
            int value = 0;
            while (pos < s.Length && char.IsDigit(s[pos]))
            {
                value = value * 10 + (s[pos] - '0');
                pos++;
            }
            return new Node(value, parent);
        }

        if (c == '(')
        {
            pos++;
            Node left = ParseExpr(s, ref pos, null);
            char operatorChar = s[pos];
            pos++;
            Node right = ParseExpr(s, ref pos, null);
            pos++;
            int opCode = operatorChar == '+' ? -1 : operatorChar == '-' ? -2 : -3;
            Node opNode = new Node(opCode, parent);
            opNode.Left = left;
            opNode.Right = right;
            left.Parent = opNode;
            right.Parent = opNode;
            return opNode;
        }

        throw new Exception($"error sybmol '{c}' on pos {pos}.");
    }

    // 3. Дана строка Ѕ, содержащая описание числового выражения в следующем формате
    // (так называемый префиксный бесскобочный формат записи числового выражения) :
    // <выражение> ::= <цифра> | <знак> <выражение> <выражение>
    // <знак> ::= +|-|*
    // Выражения отделяются друг от друга и от знаков операций ровно одним пробелом.Создать дерево разбора выражения со структурой из задания №2; для каждой вершины-операции ее левое поддерево должно соответствовать первому операнду данной операции, а правое поддерево второму.
    static Node? TreeTask3(string input)
    {
        var elems = input.Split(' ');
        int pos = 0;
        Node root = ParsePrefixExpr(elems, ref pos, null);

        return root;
    }

    static Node ParsePrefixExpr(string[] elems, ref int pos, Node? parent)
    {
        string t = elems[pos++];

        if (t.Length == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*'))
        {
            int opCode = t[0] == '+' ? -1 : t[0] == '-' ? -2 : -3;
            Node opNode = new Node(opCode, parent);
            opNode.Left = ParsePrefixExpr(elems, ref pos, opNode);
            opNode.Right = ParsePrefixExpr(elems, ref pos, opNode);
            return opNode;
        }

        if (!int.TryParse(t, out int value))
            throw new Exception($"error '{t}'");

        return new Node(value, parent);
    }

    // 4. Дана строка Ѕ, содержащая описание числового выражения в следующем формате
    // (так называемый постфиксный бесскобочный формат записи числового выражения) :
    // <выражение> ::= <цифра> | <выражение> <выражение> <знак>
    // <знак> ::= +-*
    // Выражения отделяются друг от друга и от знаков операций ровно одним пробелом.Создать дерево разбора выражения со структурой из задания №2; для каждой вершины-операции ее левое поддерево должно соответствовать первому операнду данной операции, а правое поддерево второму.
    static Node? TreeTask4(string input)
    {
        var elems = input.Split(' ');
        var stack = new Stack<Node>();

        foreach (var t in elems)
        {
            if (t.Length == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*'))
            {
                Node right = stack.Pop();
                Node left = stack.Pop();

                int operationCode = t[0] == '+' ? -1 : t[0] == '-' ? -2 : -3;
                Node operationNode = new Node(operationCode, null);

                operationNode.Left = left;
                operationNode.Right = right;
                left.Parent = operationNode;
                right.Parent = operationNode;

                stack.Push(operationNode);
            }
            else
            {
                if (!int.TryParse(t, out int value))
                    throw new Exception($"error '{t}'");
                stack.Push(new Node(value));
            }
        }

        return stack.Pop();
    }

    static void Separator(int n)
    {
        Console.WriteLine($"\n---------- Task {n} ----------");
    }

    static void Main()
    {
        Separator(1);
        string s1 = "4(2(,),6(,7(3(,),)))";
        Node? root1 = TreeTask1(s1);
        root1?.Dump();

        Separator(2);
        string s2 = "((1+2)*3)";
        Node? root2 = TreeTask2(s2);
        root2?.Dump();

        Separator(3);
        string s3 = "* + 1 2 3";
        Node? root3 = TreeTask3(s3);
        root3?.Dump();

        Separator(4);
        string s4 = "1 2 + 3 *";
        Node? root4 = TreeTask4(s4);
        root4?.Dump();
    }
}
