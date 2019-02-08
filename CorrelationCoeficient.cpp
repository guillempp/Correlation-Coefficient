//
//  CorrelationCoeficient.cpp
//  CS332
//
//  Created by Guillem Pérez on 9/5/18.
//  Copyright © 2018 Guillem Pérez. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>


void computemean(double totalxnum, int const size, double xnum[], double& meanxnum, double ynum[], double totalynum, double& meanynum);
void computevariance(double varianceaddy, double varianceaddx, double xnum[], double meanxnum, double meanynum, double& variancey, double& variancex, int const size, double ynum[]);
void computestandarddeviation(double& stdeviation, double& stdeviationy, double variancex, double variancey);
void computecorrelation(double xnum[], double ynum[], double meanxnum, double meanynum, double stdeviationx, double stdeviationy, int const size, double& precorrelation, double& correlation);

using namespace std;



int main(){
    
    const int size=10;
    
    double xnum[size]={56, 65, 47, 57, 62, 48, 68, 75, 79, 49};
    double ynum[size]={45, 49, 35, 44, 45, 40, 52, 57, 62, 39};
    double totalxnum;
    double meanxnum;
    double totalynum;
    double meanynum;
    double varianceaddy = 0;
    double varianceaddx = 0;
    double variancex;
    double variancey;
    double stdeviationx;
    double stdeviationy;
    double precorrelation = 0;
    double correlation;
    
    

    computemean(totalxnum, size, xnum, meanxnum, ynum, totalynum, meanynum);
    computevariance(varianceaddy, varianceaddx, xnum, meanxnum, meanynum, variancey, variancex, size, ynum);
    computestandarddeviation(stdeviationx, stdeviationy, variancey, variancex);
    computecorrelation(xnum, ynum, meanxnum, meanynum, stdeviationx, stdeviationy, size, precorrelation, correlation);
    
    //Critical values .05 for n-1 of 9 is .666 and .01 is 798
    if (correlation > .666 && correlation > .798){
        if (correlation > 0){
            cout<<"The conclussion is: significant positive linear correlation"<<endl;
        }else{
            cout<<"The conclussion is: significant negative linear correlation"<<endl;
        }
    }else{
    
        cout<<"The conclussion is: no linear correlation"<<endl;

    }
    
}


void computemean(double totalxnum, int const size, double xnum[], double& meanxnum, double ynum[], double totalynum, double& meanynum){
    for(int y=0; y<size; y++){
        totalxnum += xnum[y];
        totalynum += ynum[y];
    }
    
    meanxnum = totalxnum / size;
    meanynum = totalynum / size;
    
    cout<<"The Mean for x is: "<<meanxnum<<endl;
    cout<<"The Mean for y is: "<<meanynum<<endl;
    
}
void computevariance(double varianceaddy, double varianceaddx, double xnum[], double meanxnum, double meanynum, double& variancey, double& variancex, int const size, double ynum[]){
    
    for (int i = 0; i < size; i++){
        varianceaddx = varianceaddx + pow(xnum[i]-meanxnum, 2);
        varianceaddy = varianceaddy + pow(ynum[i]-meanynum, 2);
        
    }
    
    variancex = varianceaddx / 9;
    variancey = varianceaddy / 9;
    
    cout<<"The variance for x is: "<<variancex<<endl;
    cout<<"The variance for y is: "<<variancey<<endl;
    
}
void computestandarddeviation(double& stdeviationx, double& stdeviationy, double variancey, double variancex){
    
    stdeviationx = sqrt(variancex);
    stdeviationy = sqrt(variancey);
    
    cout<<"The standard deviation for x is: "<<stdeviationx<<endl;
    cout<<"The standard deviation for y is: "<<stdeviationy<<endl;
    
}

void computecorrelation(double xnum[], double ynum[], double meanxnum, double meanynum, double stdeviationx, double stdeviationy, int const size, double& precorrelation, double& correlation){
    
    for(int i=0; i<size; i++){
        precorrelation = precorrelation + (xnum[i]-meanxnum)*(ynum[i]-meanynum);
        
    }
    
    correlation = (precorrelation/9) / (stdeviationx*stdeviationy);
    cout<<"The correlation coeficient for the given data is: "<<correlation<<endl;
    
}


