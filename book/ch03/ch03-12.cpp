#include <iostream>
#include <string>

using std::string; using std::cout; using std::cin;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    string subseq, seq;

    while(cin >> subseq >> seq)
    {
        int index_subseq = 0, index_seq = 0;
        bool flag = false;
        for(; index_seq < seq.size(); index_seq++)
        {
            if(subseq[index_subseq] == seq[index_seq])
            {
                index_subseq++;
                if(index_subseq == subseq.size())
                {
                    cout << "Yes\n";
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
            cout << "No\n";
    }
}