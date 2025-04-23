namespace cs162c_recursive_algos;

class Program
{
    
    static bool TestRowSort(int[,] array, int[,] expected) {

        // TODO: call sorting function

        // Check each value is as expected
        if (array.Length != expected.Length)
        {
            return false;
        }
        
        for (int i=0; i < array.GetLength(0); i++) {
            for (int j=0; j < array.GetLength(1); j++) {
                if (array[i,j] != expected[i,j]) {
                    return false;
                }
            }
        }

        return true;
    }

    static bool TestRowSort0() {
        int[,] array0 = {
            { 1, 2, 13, 0},
            { 12, 6, -1, 2}
        };
        int[,] expectedResult = {
            { 0, 1, 2, 13},
            { -1, 2, 12, 6 }
        };
        
        return TestRowSort(array0, expectedResult);
    }

    static void Main(string[] args)
    {
        Console.WriteLine("test0 {0}", TestRowSort0());
    }
}