
/*


1          1
12        21
123      321
1234    4321
12345  54321
123456654321




#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j,m,k;
	int s;
	s = 9;
	for(i = 1; i <= 6; i++)
	{
		for(j = 1; j <= i; j++)
		{
			cout<<j;
			
		}
		for(int m = s; m >= 0 ; m--)
		{
			cout<<" ";
		}
		s = s - 2;
		for(k = i; k > 0; k--)
		{
			cout<<k;
		}
		
		cout<<endl;
	}
	return 0;
}




    1
   121
  12321
 1234321


#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j,m,k;
	for(i = 0; i <= 4; i++)
	{
		for(int m = 5; m > i; m--)
		{
			cout<<" ";
		}
		for(j = 0; j < i; j++)
		{
			cout<<j+1;
			
		}
		for(k = i-2; k >= 0; k--)
		{
			cout<<k+1;
		}
		
		cout<<endl;
	}
	return 0;
}





              aa      
		   	 abba     
		    abccba  
		   abcddcba 
		   
		        
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j,m,k;
	char bit[] = "abcd";
	for(i = 0; i <= 4; i++)
	{
		for(int m = 5; m > i; m--)
		{
			cout<<" ";
		}
		for(j = 0; j < i; j++)
		{
			cout<<bit[j];
			
		}
		for(k = i-1; k >= 0; k--)
		{
			cout<<bit[k];
		}
		
		cout<<endl;
	}
	return 0;
}





 * * * * *
  * * * *
   * * *
    * *
     *

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j,m;
	for(i = 5; i > 0; i--)
	{
		for(int m = i; m < 5; m++)
		{
			cout<<" ";
		}
		for(j = 1; j <= i; j++)
		{
			cout<<" *";
			
		}
		cout<<endl;
	}
	return 0;
}



     *
    * *
   * * *
  * * * *
 * * * * *


#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j,m;
	for(i = 1; i <= 5; i++)
	{
		for(int m = 5; m > i; m--)
		{
			cout<<" ";
		}
		for(j = 1; j <= i; j++)
		{
			cout<<" *";
			
		}
		cout<<endl;
	}
	return 0;
}



COMPUTER
COMPUTE
COMPUT
COMPU
COMP
COM
CO
C


#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

int main()
{
    char string[] = "COMPUTER";
	int len;
	len = strlen(string);
	for(int i = len-1; i >= 0; i--)
	{
		for(int j = 0; j <=i; j++)
		{
			cout<<string[j];
		}
		cout<<endl;
	}
	return 0;
}



   1
   2   3
   4   5   6
   7   8   9  10
  11  12  13  14  15



#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j;
	int k =1;
	for(i = 1; i <= 5; i++)
	{
		for(j = 1; j <= i; j++)
		{
			cout<<setw(4)<<k;
			k++;
		}
		cout<<endl;
	}
	return 0;
}



 1 2 3 4 5
 2 3 4 5
 3 4 5
 4 5
 5


#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,j;
	for(i = 1; i <= 5; i++)
	{
		for(j = i; j <= 5; j++)
		{
			cout<<setw(2)<<j;
		}
		cout<<endl;
	}
	return 0;
}



 1 1 1 1 1
 2 2 2 2
 3 3 3
 4 4
 5

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,k;
	for(i = 1,k = 5; k > 0; i++,k--)
	{
		for(int j = 1; j <= k; j++)
		{
			cout<<setw(2)<<i;
		}
		cout<<endl;
	}
	return 0;
}



 * * * * *
 * * * *
 * * *
 * *
 *


#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i,k;
	for(i = 1,k = 5; k > 0; i++,k--)
	{
		for(int j = 1; j <= k; j++)
		{
			cout<<setw(2)<<"*";
		}
		cout<<endl;
	}
	return 0;
}



 1
 2 1
 3 2 1
 4 3 2 1
 5 4 3 2 1

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = i; j >= 1; j--)
		{
			cout<<setw(2)<<j;
		}
		cout<<endl;
	}
	return 0;
}


 1
 1 2
 1 2 3
 1 2 3 4
 1 2 3 4 5
 
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cout<<setw(2)<<j;
		}
		cout<<endl;
	}
	return 0;
}



 1
 0 1
 1 0 1
 0 1 0 1
 1 0 1 0 1
 
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = i; j >= 1; j--)
		{
			cout<<setw(2)<<j%2;
		}
		cout<<endl;
	}
	return 0;
}


 1
 1 0
 1 0 1
 1 0 1 0
 1 0 1 0 1

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cout<<setw(2)<<j%2;
		}
		cout<<endl;
	}
	return 0;
}

 
 *
 * *
 * * *
 * * * *
 * * * * *
 
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cout<<setw(2)<<"*";
		}
		cout<<endl;
	}
	return 0;
}

*/
