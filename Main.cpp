//
//  main.cpp
//  Magic Square
//
//  Created by Leroy on 02/03/2020.
//  Copyright © 2020 Leroy. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <memory.h>

using namespace std;
int main(int argc, const char * argv[]) {
    cout<<"Pls enter square's size (n is an odd number which larger than 1 )"<<endl;
    int n;
    cin>>n;
    cout<<endl;
    int **a = new int *[n];
    
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
        memset(a[i], 0, n*sizeof(int));
    }
    int row = 0;
    int col = n/2;              //at the middle of first row
    
    /* Total number is n*n */
    for(int i = 1; i < n*n; i++){
        a[row][col] = i;        //Top left
        row--;
        col++;
        /* if beyond the range */
        if(row<0 && col>=n){        //move to row = 0 && col == n
            col--;
            row += 2;
        }
        else if(row<0){            //move to the last row
            row = n-1;
        }
        else if(col>=n){            //move to the first col
            col = 0;
        }
        else if (a[row][col]!=0){   //if there already had a number, move to top right
            col--;
            row += 2;
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(6)<<a[i][j];         //print out
        cout<<endl;
    }
    
    for(int i = n ; i > 0;)
        delete[] a[--i];                //clean column
    delete[] a;                         //clean row
    
    return 0;
}
