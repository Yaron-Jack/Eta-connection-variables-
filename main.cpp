/***************************

 Stat - connection between two  variables

 Eta,Pirsa

 PART 2

 ***************************/




#include <iostream>
#include <vector>

using namespace std;


/*** string multiplier operator***/
string operator*(string a, unsigned int b)
{
    string output = "";
    while (b--)
    {
        output += a;
    }
    return output;
}

void PrintTable(vector<vector<float> > &Board, int &ColumnInputTable, int &RowInputTable)
{
    string Divide = "-------------";
    cout << "\n" << (Divide * RowInputTable) << endl;

    for (int i = 0; i < Board.size(); ++i)
    {
        for (int j = 0; j < Board[i].size(); ++j)
        {
            cout << Board[i][j] << "         |";
        }
        cout << "Row" << i << endl;
        cout << (Divide * Board[i].size()) << endl;
    }
}

void
RepeatingInput(vector<vector<float> > &Board, int &ColumnInputTable, int &RowInputTable, float &Sum, float &MiddleFxSum,
               float &FxSum, float &SquareMiddleFx, float &SumSizeFrequency)
{
    float InputChoice = 0;

    for (int i = 0; i < Board.size() - 2; ++i)
    {
        float RowLoopingSum = 0;

        for (int j = 0; j < Board[i].size() - 1; ++j)
        {
            if (i == 0 && j == 0)
            {
                Board[i][j] = 0;
            }
            else if (i == 0 && j == Board[i].size() - 1)
            {
                Board[i][j] = 0;
            }
            else if (j < Board[i].size() - 2)
            {
                cout << "\n\tRemember first Column and row are the variables \"name\" " << "\n" << endl;
                cout << "\n\tPlease enter input for the following place\n\t" << i << " " << j << "\n"
                     << flush;

                if (cin >> InputChoice)
                {
                    Board[i][j] = InputChoice;

                    PrintTable(Board, ColumnInputTable, RowInputTable);

                    if (j != 0)
                    {
                        RowLoopingSum += Board[i][j];
                    }

                }
            }
            else
            {
                Board[i][j] = RowLoopingSum;

                PrintTable(Board, ColumnInputTable, RowInputTable);
            }
        }
    }
    for (int j = 1; j < Board[0].size(); j++)
    {
        for (int i = 1; i < Board.size(); i++)
        {
            Sum += Board[i][j];
        }
        Board[Board.size() - 2][j] = Sum;
        Sum = 0;
    }
    PrintTable(Board, ColumnInputTable, RowInputTable);
}


void Eta(vector<vector<float> > &Board,
         int &RowInputTable)///TODO fix me!
{
    float Ly = 0;
    float Lx = 0;
    float Lyx = 0;
    float Lxy = 0;
    float AddedLxy = 0;
    float L = 0;
    float SpecialY = 0;
    float AddedLy = 0;
    float AddedLx = 0;
    float AddedLyx = 0;
    float AddedLyxLoop = 0;
    float Specialx = 0;
    float NewL = 0;

    for (int i = 0; i < Board.size() - 1; ++i)
    {
        AddedLx += Board[i][RowInputTable] * Board[i][0];
        cout << "Added Lx is: " << AddedLx << endl;
    }

    Specialx = AddedLx / Board[Board.size() - 2][RowInputTable];
    cout << "Special Lx is: " << Specialx << endl;

    for (int i = 1; i < Board.size() - 2; ++i)
    {
        Lx += (Board[i][0] - Specialx) * (Board[i][0] - Specialx) * Board[i][RowInputTable];
        cout << "Lx on it's way is is: " << Lx << endl;

    }

    cout << "Lx finally is: " << Lx << endl;


    for (int i = 1; i < RowInputTable; i++)
    {

        for (int j = 1; j < Board.size() - 2; ++j)//fix
        {

            AddedLxy += Board[j][i] * Board[j][0] / Board[Board.size() - 2][i];
            cout << "Added Lyx is: " << AddedLxy << endl;

        }
        Board[Board.size() - 1][i] = AddedLxy;
        AddedLxy = 0;
    }

    for (int i = 1; i < RowInputTable; i++)
    {
        for (int j = 1; j < Board.size() - 2; ++j)//fix
        {
            Lxy += Board[j][i] *
                   ((Board[j][0] - Board[Board.size() - 1][i]) * (Board[j][0] - Board[Board.size() - 1][i]));
            cout << "Lxy on its way is: " << Lxy << endl;
        }
    }

    cout << "Lxy finally is: " << Lxy << endl;
    NewL = sqrt((Lx - Lxy) / Lx);

    cout << "****************************" << endl;
    cout << "\nPredicted that Lambda y is:" << NewL * 100 << "%\n" << endl;
    cout << "****************************" << endl;

    cout << char(1) << " Hooray! " << char(1) << endl;

    //Second Lambda
    for (int i = 0; i < Board.size() - 1; ++i)
    {
        Board[i][RowInputTable + 1] = 0;
    }

    NewL = 0;

    for (int i = 0; i < RowInputTable; ++i)
    {
        AddedLy += Board[Board.size() - 2][i] * Board[0][i];
        cout << "Added Ly is: " << AddedLy << endl;
    }

    SpecialY = AddedLy / Board[Board.size() - 2][RowInputTable];
    cout << "Special Ly is: " << SpecialY << endl;

    for (int i = 0; i < RowInputTable; ++i)
    {
        Ly += (Board[0][i] - SpecialY) * (Board[0][i] - SpecialY) * Board[Board.size() - 2][i];
        cout << "Ly on it's way is is: " << Ly << endl;

    }

    cout << "Ly finally is: " << Ly << endl;


    for (int i = 1; i < Board.size() - 2; i++)
    {

        for (int j = 1; j < RowInputTable; ++j)
        {
            AddedLyx += Board[i][j] * Board[0][j] / Board[i][RowInputTable];
            cout << "Added Lyx is: " << AddedLyx << endl;
            Board[i][RowInputTable + 1] = AddedLyx;

        }
        AddedLyx = 0;
    }
    for (int i = 1; i < Board.size() - 2; ++i)
    {
        for (int j = 1; j < RowInputTable; ++j)
        {
            Lyx += Board[i][j] *
                   ((Board[0][j] - Board[i][RowInputTable + 1]) * (Board[0][j] - Board[i][RowInputTable + 1]));

        }
    }
    cout << "Lyx finally is: " << Lyx << endl;
    NewL = sqrt((Ly - Lyx) / Ly);

    cout << "****************************" << endl;
    cout << "\nPredicted that Lambda X is:" << NewL * 100 << "%\n" << endl;
    cout << "****************************" << endl;

    cout << char(1) << " Hooray! " << char(1) << endl;

}

int main()
{
    cout << "\n\n\tStatistics - Eta \n\n";

    int ColumnInputTable, RowInputTable = 0;
    float Sum = 0;
    float MiddleFxSum, FxSum = 0;
    float SquareMiddleFx = 0;
    float SumSizeFrequency = 0;
    float LoopingHighestFrequency, LoopingHighestFrequency2, FinalMiddleRange, FinalAverage, FinalStandardDeviation = 0;


    cout << "\nplease enter the Board size columns followed by rows: \n" << flush;
    cin >> ColumnInputTable;
    cin >> RowInputTable;

    ///create a vector of vectors for the board with input each time
    vector<vector<float>> Board(ColumnInputTable + 2, vector<float>(RowInputTable + 2, 0));

    PrintTable(Board, ColumnInputTable, RowInputTable);

    RepeatingInput(Board, ColumnInputTable, RowInputTable, Sum, MiddleFxSum,
                   FxSum, SquareMiddleFx, SumSizeFrequency);


    cout << "\n\tWelcome to Eta Connection between variables\n" << endl;


    Eta(Board, RowInputTable);

    PrintTable(Board,ColumnInputTable,RowInputTable);

    return 0;
}
/*******
TODO just copy paste from stat
 Also think of how you'd like the board to be - with what numbers at the start


*/