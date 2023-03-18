// circlechess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
void interface(string &a, string &b)
{
    cout << "请输入玩家a的昵称:";
    cin >>a;
    cout << "请输入玩家b的昵称:";
    cin >>b;
}
void boardprint(vector<string>board)
{
    for (string row : board) { cout << row ; cout << "\n"; }
}
void winning(vector<string>&board,int&result,int drop)
{
    int line = (drop - 1) / 3;
    int row = (drop - 1) % 3;
    if (board[line][0] == board[line][1] && board[line][0]==board[line][2]) { result = 1; }
    if (board[0][row] == board[1][row] && board[0][row] == board[2][row]) { result = 1; }
    if (drop == 1 || drop == 5 || drop == 9)
    {
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){ result = 1; }
    }
    if (drop == 3 || drop == 5 || drop == 7)
    {
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) { result = 1; }
    }
}
void gameplay(string a, string b,vector<string> board)
{
    int result = 0;
    int count = 1;
    int drop;
    while (result == 0)
    {
        if (count > 9) { result = 2; break; }
        if (count%2==1) { cout << "请玩家" << a << "下棋" << "\n"; cin >> drop; }
        else { cout << "请玩家" << b << "下棋" << "\n"; cin >> drop; }
        if (drop < 0 || drop>9) { cout << "输入错误，请重新输入" << "\n"; continue; }
        if (board[(drop - 1) / 3][(drop - 1) % 3] == '*') {
            if (count % 2 == 1) { board[(drop - 1) / 3][(drop - 1) % 3] = 'o'; }
            else { board[(drop - 1) / 3][(drop - 1) % 3] = 'x'; }
        }
        else { cout << "此处已经落子请重新输入"<<"\n"; continue; }
        winning(board, result, drop);
        boardprint(board);
        ++count;
    }
    if (result == 1) {
        if (count % 2 == 1) { cout << "玩家" << a << "获得胜利！"; }
        else { cout << "玩家" << b << "获得胜利！"; }
    }
    else { cout << "和局！"; }
}
int main()
{
    cout << "欢迎来到井字棋游戏，本游戏的规则是每一个棋盘格从左往右数，对应数字123456789，玩家输入对应数字即可落子于对应棋盘上，先连上三子的玩家获胜，祝你玩得愉快。";
    cout << "\n";
    string a, b;
    vector<string>board = { {"***"},{"***"},{"***"} };
    interface(a, b);
    gameplay(a, b, board);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
