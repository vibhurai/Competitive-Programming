#include <bits/stdc++.h>
using namespace std;

void print_sequence(vector<vector<string>> seq, int o, int p)
{

    int o0 = 0;
    int p0 = 0;

    if (o == 0 && p == 0)
    {
        return;
    }

    if (seq[o][p] == "copy" || seq[o][p] == "replace")
    {
        o0 = o - 1;
        p0 = p - 1;
    }

    else if (seq[o][p] == "twiddle")
    {
        o0 = o - 2;
        p0 = p - 2;
    }
    else if (seq[o][p] == "delete")
    {
        o0 = o - 1;
        p0 = p;
    }
    else if (seq[o][p] == "insert")
    {
        o0 = o;
        p0 = p - 1;
    }

    print_sequence(seq, o0, p0);

    cout << seq[o][p] << endl;
}

double edit_distance(vector<vector<string>> sequence, string x, string y)
{

    double solution[x.length() + 1][y.length() + 1];

    for (int i = 0; i <= x.length(); i++)
    {
        vector<string> temp;
        for (int j = 0; j <= y.length(); j++)
        {
            temp.push_back("");
        }
        sequence.push_back(temp);
    }

    for (int i = 0; i <= y.length(); i++)
    {

        solution[0][i] = i * 1;

        sequence[0][i] = "insert"; //op is matrix for tracking back operations
    }

    for (int i = 0; i <= x.length(); i++)
    {
        solution[i][0] = i * 1;
        sequence[i][0] = "deletee";
    }

    int m = x.length();
    int n = y.length();

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            if (x[(i - 1)] == y[(j - 1)])
            {
                solution[i][j] = solution[i - 1][j - 1] + 0; //copy
                sequence[i][j] = "copy";
            }
            else if (x[(i - 1)] != y[(j - 1)])
            {

                double replace = solution[i - 1][j - 1] + 2; // replace
                double insert = solution[i][j - 1] + 1;      //insert
                double deletee = solution[i - 1][j] + 1;     //deletee

                double min;

                if (replace <= insert)
                {
                    min = replace;
                    sequence[i][j] = "replace";
                    solution[i][j] = min;
                }
                else
                {

                    min = insert;
                    sequence[i][j] = "insert";
                    solution[i][j] = min;
                }

                if (min > deletee)
                {
                    min = deletee;
                    sequence[i][j] = "delete";
                    solution[i][j] = min;
                }
            }

            if (i > 1 && j > 1 && x[(i - 1)] == y[(j - 2)] && x[(i - 2)] == y[(j - 1)] && (solution[i - 2][j - 2] + 1.5) < solution[i][j])
            {
                solution[i][j] = solution[i - 2][j - 2] + 1.5; //twiddle
                sequence[i][j] = "twiddle";
            }

        } //end of j for loop

    } //end of i for loop

    for (int i = 0; i <= m - 1; i++)
    {

        if ((solution[i][n] + 5) < solution[m][n])
        {
            solution[m][n] = solution[i][n] + 5; //kill
            sequence[m][n] = "kill " + (i + 1);
        }
    }

    cout << "\nSequence of operations : \n";

    print_sequence(sequence, x.length(), y.length()); //to print sequence

    return solution[m][n]; //return cost
}

int main()
{
    string one = "algorithm", two = "altruistic";

    // cout << "\nEnter first string : ";
    // cin >> one;
    // cout << "\nEnter second string : ";
    // cin >> two;

    vector<vector<string>> main_operations;

    double result = edit_distance(main_operations, one, two);
    cout << "\nThe steps most optimal set of instructions for getting y from x : " << result;
}