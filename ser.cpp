#include<bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;


int main(int argc, char *argv[]){
    auto start = high_resolution_clock::now();
    int n;
    //in >> n;
    // double a[n][n];
    // int *arr = new int(n);
    // srand(time(NULL));
    sscanf(argv[1], "%d", &n);
    double** a = new double*[n];
 
    for (int i = 0; i < n; i++) {       
        a[i] = new double[n];
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cin >> a[i][j];
            a[i][j] = rand()%1000;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // cin >> a[i][j];
            cout << a[i][j] << "\t"; 
        }
        cout << endl;
    }


    int k_dash = 0; 
    // double p[n], l[n][n], u[n][n], lu[n][n],pa[n][n];
    // double* p = new double[n];
    double p[n];
    double** l = new double*[n];
 
    for (int i = 0; i < n; i++) {       
        l[i] = new double[n];
    }    
    double** u = new double*[n];
 
    for (int i = 0; i < n; i++) {       
        u[i] = new double[n];
    }
    double** lu = new double*[n];
 
    for (int i = 0; i < n; i++) {       
        lu[i] = new double[n];
    }
    double** pe = new double*[n];
 
    for (int i = 0; i < n; i++) {       
        pe[i] = new double[n];
    }

    for(int i=0;i<n;i++){
        p[i] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                u[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                l[i][j] = 0;
            }
            else if(i == j)
                l[i][j] = 1;

        }
    }

    for(int k = 0;k<n;k++){
        int max = 0;
        for(int i = k;i<n;i++){
            if(max < abs(a[i][k])){
                max = abs(a[i][k]);
                k_dash = i;
            }
        }
        if(max == 0){
            cout << "singular matrix" << endl;
            return 0;
        } 
        swap(p[k], p[k_dash]);
        for(int i=0;i<n;i++){
            swap(a[k][i], a[k_dash][i]);
        }
        for(int i=0;i<k;i++){
            swap(l[k][i], l[k_dash][i]);
        }
        u[k][k] = a[k][k];
        for(int i=k+1;i<n;i++){
            l[i][k] = a[i][k]/u[k][k];
            u[k][i] = a[k][i];
        }
        for(int i= k+1;i<n;i++){
            for(int j=k+1;j<n;j++){
                a[i][j] = a[i][j] - l[i][k]*u[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << p[i] << " ";
    }
    
    cout << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << l[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << u[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            lu[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                lu[i][j] += l[i][k] * u[k][j];
            }
        }
    }

    cout << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << lu[i][j] << "\t";
        }
        cout << endl;
    }
    
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(j == p[i])
    			pe[i][j] = 1;
    		else 
    			pe[i][j] = 0;
    	}
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << pe[i][j] << "\t";
        }
        cout << endl;
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    int timeTaken = duration.count()/1000;
    cout << timeTaken << endl;
    
    ofstream myfile;
    myfile.open ("serialOutput.txt", ios::app);
    myfile << n<<","<<timeTaken << endl;
    myfile.close();
    
    return 0;

}

