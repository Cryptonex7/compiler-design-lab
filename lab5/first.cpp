#include<bits/stdc++.h>

using namespace std;

class First {
    stack<char> f;
};

void first_i (char c[80], int P, char x[][80], stack<char> f[]){
    // if(!isupper(c[2]))
    //     f[P].push(c[2]);
    // else if (isupper(c[3]))
    //     for(int j = 0; j<P; j++)
    //         if(x[j][0] == c[2])
    //             first_i(x[j], j, x, f);
    for(int i = 0; i<80; i++)
        if(c[i] == '|' || c[i] == '=')
            if(!isupper(c[i+1]))
                f[P].push(c[i+1]);
            else if (isupper(c[i+2]))
                for(int j = 0; j<P; j++)
                    if(x[j][0] == c[i+1])
                        first_i(x[j], j, x, f);
}

void first(char x[][80], int P, stack<char> f[]){
    for (int i = 0; i < P; i++)
        first_i(x[i], i, x, f);
}

int main() {
    int P;
    cout<<"Enter number of Productions: ";
    cin>>P;

    string prod[P];
    for( int i = 0 ;i<P; i++)
        cin>>prod[i];
    
    char char_array[P][80]; 
    for( int i = 0 ;i<P; i++)
        strcpy(char_array[i], prod[i].c_str()); 

    stack<char> f[P];
    first(char_array, P, f);

    for( int i = 0 ;i<P; i++){
        cout<<"First("<<char_array[i][0]<<") = "<<"{ ";
        while(!f[i].empty()){
            cout<<f[i].top()<<", ";
            f[i].pop();
        }
        cout<<"}\n";
    }
    cout<<endl<<endl;
}


// void first(char c)
// {
//     int k;
//     if (!isupper(c))
//         f[m++] = c;
//     for (k = 0; k < n; k++)
//     {
//         if (a[k][0] == c)
//         {
//             if (a[k][i+1] == '$')
//                 follow(a[k][0]);
//             else if (islower(a[k][2]))
//                 f[m++] = a[k][2];
//             else
//                 first(a[k][2]);
//         }
//     }
// }
// void follow(char c)
// {
//     if (a[0][0] == c)
//         f[m++] = '$';
//     for (i = 0; i < n; i++)
//     {
//         for (j = 2; j < strlen(a[i]); j++)
//         {
//             if (a[i][j] == c)
//             {
//                 if (a[i][j + 1] != '\0')
//                     first(a[i][j + 1]);
//                 if (a[i][j + 1] == '\0' && c != a[i][0])
//                     follow(a[i][0]);
//             }
//         }
//     }
// }
