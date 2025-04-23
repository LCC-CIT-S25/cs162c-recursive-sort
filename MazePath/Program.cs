namespace MazePath;

class Program
{
    
    static bool TestMaze(int[,] maze, int expectedCost) {
        int minCost0 = 0;
        // TODO: Add calls to test functions
        // minCost0 = /* replace with call */;

        if (expectedCost != minCost0) {
            Console.WriteLine("Calculate minimum cost for maze0 {0} != {1} (expected min cost)",
                minCost0, expectedCost);
            return false;
        }

        return true;
    }

    static bool TestMaze0() {
        const int expectedMinCost0 = 7;
        // array must be declared with MAX D1 for functions to work.
        int[,] testMaze0 = {
            { 1, 1, 1, 1},
            { 2, 2, 6, 3},
            { 5, 1, 1, 1},
        };

        return TestMaze(testMaze0, expectedMinCost0);
    }
    static void Main(string[] args)
    {
        Console.WriteLine("testMaze0: {0}", TestMaze0());
    }
}