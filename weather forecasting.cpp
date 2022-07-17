#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
float case1=0,case2=0,case3=0;
float c11=0,c12=0,c13=0,c21=0,c22=0,c23=0,c31=0,c32=0,c33=0;
void persentage(float a);
int main()
{
int n
=12;
cout<<"Enter 12 average temperatures for the desired month during the last 12 years"<<endl;
float mat[12];
for (int l;l<12;l++)
    cin>>mat[l];

 for(int i=0;i<n-1;i++)
 {
     if (mat[i]>=20.0&&mat[i]<23.0)
     case1++;
     if (mat[i]>=23.0&&mat[i]<26.0)
        case2++;
    if (mat[i]>=26.0&&mat[i]<29.0)
        case3++;}
        /* Transition matrix */
        for(int i=0;i<n;i++){
if (mat[i]>=20&&mat[i]<23&&mat[i+1]>=20&&mat[i+1]<23){c11++;}
if (mat[i]>=20&&mat[i]<23&&mat[i+1]>=23&&mat[i+1]<26){c12++;}
if (mat[i]>=20&&mat[i]<23&&mat[i+1]>=26&&mat[i+1]<29){c13++;}
if (mat[i]>=23&&mat[i]<26&&mat[i+1]>=20&&mat[i+1]<23){c21++;}
if (mat[i]>=23&&mat[i]<26&&mat[i+1]>=23&&mat[i+1]<26){c22++;}
if (mat[i]>=23&&mat[i]<26&&mat[i+1]>=26&&mat[i+1]<29){c23++;}
if (mat[i]>=26&&mat[i]<29&&mat[i+1]>=20&&mat[i+1]<23){c31++;}
if (mat[i]>=26&&mat[i]<29&&mat[i+1]>=23&&mat[i+1]<26){c32++;}
if (mat[i]>=26&&mat[i]<29&&mat[i+1]>=26&&mat[i+1]<29){c33++;}
 }
float trans[3][3]{(c11/case1),(c12/case2),(c13/case3),(c21/case1),(c22/case2),(c32/case3),(c31/case1),(c23/case2),(c33/case3)};
        /* initial matrix matrix */
        float in[3] {0,0,0};
        if (mat[11]>=20.0&&mat[11]<23.0)
     in[0]=1;
     if (mat[11]>=23.0&&mat[11]<26.0)
        in[1]=1;
    if (mat[11]>=26.0&&mat[11]<29.0)
        in[2]=1;
        /*  multiplication  */
 float mul [3][1];
for(int i=0;i<3;i++)
{
for(int j=0;j<1;j++)
{
mul[i][j]=0;
for(int k=0;k<3;k++)
{
mul[i][j]+=trans[i][k]*in[k];
}
}
}
for(int i=0;i<3;i++)
{
    for(int j=0;j<1;j++)
{
cout<< "The probability that the average temperature in the next year will be in the case number "<<i+1<<" is "<<mul[i][j]*100.0<<" %"<<endl;
}
}
}
/*The data used in our experiment :
26.2
23.45
20.5
25.76
23.65
22.4
26.85
22.85
28.5
22
22
23.85
*/

