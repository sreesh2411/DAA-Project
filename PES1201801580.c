#include<string.h>
#include<stdlib.h>
#include<stdio.h>

static char** createarray(int x)  //Creating an array of characters of length x.   
{
	char **s = malloc(sizeof(char *)*x);
    	return s;
}

static void reversestring(char *a) //Function to reverse the string.
{ 
    	int n = strlen(a); 
    	for (int i = 0; i < n/2; i++) 
	{
        	char b=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=b;
	} 
}

static char *copy(const char *a)  //Copy a string a to string y.
{
	int length = strlen(a);
  	char *y = malloc(sizeof(char)*(length+1));
    	for(int i = 0; i <= length; i++)
	{
       		y[i] = a[i];
    	}
    	return y;
}

static int isequal(const char *x, const char *y)  //Function to help us check whether a & b are equal.
{
	if(strlen(x) != strlen(y))  //Checking if the lengthd are equal
	{
		return 0;
	}
    	int v = strlen(y);
    	for(int i = 0; i < v; i++)
	{
	        if(x[i] != y[i])
		{
	            return 0;
	        }
 	}
    	return 1;
}

static int greater(const char *a, const char *b)  //Checking which intal is larger.
{
	for(int i = 0; i < strlen(b); i++)
	{
		if(b[i] > a[i])
		{
			return 0;
		}
		else if(a[i] > b[i])
		{
			return 1;
		}
	}
	return 1;
}

static char* conversion(int unsigned n)  //Converting an integer to string.
{
	char *res;
	int c=0;
	int m=n;
	while(m)
	{
		c++;
		m/=10;
	}
	res=malloc(sizeof(char)*(c+1));  //Creating an empty string.
	res[c--]='\0';  //Equating the last value of string to \0 to terminate the string(null terminator).
	while(n)
	{
		res[c--]=48+n%10;
		n/=10;
	}
	return res;
} 


// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(const char* intal1, const char* intal2)
{
	if(strlen(intal1) > strlen(intal2))
	{
		return 1;
	}
	else if(strlen(intal1) < strlen(intal2))
	{
		return -1;	
	}
	else
	{
		for(int i = 0; i < strlen(intal1); i++)
		{
			if(intal1[i]>intal2[i])
			{
				return 1;
			}
			else if(intal1[i]<intal2[i])
			{
				return -1;
			}
		}
	return 0;
	}
}


// Returns the sum of two intals.
char* intal_add(const char* intal1, const char* intal2)
{
	char *intal11 = copy(intal1);
	char *intal22 = copy(intal2);
	int x = strlen(intal11);
	int y = strlen(intal22);
	char *res;
	int n = x>y?x:y;
	if(intal_compare(intal22,intal11) == 1)
	{
		char *temp = intal11;
		intal11 = intal22;
		intal22 = temp;
	}
	int min = (n == x)?y:x;
	res = (char *)malloc(sizeof(char)*(n+2));
	reversestring(intal11);
	reversestring(intal22);
	int carry = 0;
	int m = 0;
	for (int i = 0; i < min; i++) 
    	{ 
        	int sum = (intal11[i]-'0')+(intal22[i]-'0') + carry; 
        	res[m++] = 48 + sum%10;
        	carry = sum/10; 
    	} 
  
    	for (int i = min; i < n; i++) 
    	{ 
     		int sum = (intal11[i]-'0')+carry; 
        	res[m++]=48 + sum%10;
        	carry = sum/10;  
    	} 
  
 
    	if (carry)
	{ 
	        res[m++] = 48+carry;
	} 
	res[m]='\0';
  
    	reversestring(res);
	free(intal11);
	free(intal22);
    	return res; 
}

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(const char* intal1, const char* intal2)
{
	char *intal11 = copy(intal1);
	char *intal22 = copy(intal2);
	int com = intal_compare(intal22,intal11);
	if(com == 0)
	{
		char *res = malloc(sizeof(char)*2);
		res[0]=48;
		res[1]='\0';
		return res;
	}
	if(com == 1)
	{
		char *l = intal11;
		intal11 = intal22;
		intal22 = l;
	}
	int a = strlen(intal11);
	int b = strlen(intal22);
	char *res;

	int n = a>b?a:b;

	int min = (n == a)?b:a;
	res = (char *)malloc(sizeof(char)*(n+2));
	reversestring(intal11);
	reversestring(intal22);
	int carry = 0;
	int m = 0;
	for (int i = 0; i < min; i++) 
	    { 
        int sum = (intal11[i]-'0')-(intal22[i]-'0')-carry;
		if(sum < 0)
		{
			sum+=10; 
			carry=1;
		}
		    
		else
		{
		carry = 0;
		}
		res[m++]=48 + sum;
	    } 
	  
	    for (int i = min; i < n; i++) 
	    { 
	     int sum = (intal11[i]-'0')-carry;
		if(sum<0)
		{
			sum += 10; 
			carry = 1;}
		else{
			carry = 0;}
	        res[m++] = 48 + sum;  
	    }
	m--;
	while(res[m] == 48)
	{
		m--;
	}
	m++;
	res[m]='\0';
  
	reversestring(res);
	free(intal11);
	free(intal22);
    
	    return res; 
}

// Returns the product of two intals.
char* intal_multiply(const char* intal1, const char* intal2)
{
	if(intal1[0] == 48 || intal2[0] == 48)
	{
	char *res = (char*)malloc(sizeof(char)*2);
	res[0] = 48;
	res[1] = '\0';
	return res;
	}
	int a = strlen(intal1);
	int b = strlen(intal2);
	    char *result = malloc(sizeof(char)*(a+b+2));  
	    int i_n1 = 0;  
	    int i_n2 = 0;  
	    int i;
	    for(int i = 0; i < a+b+2; i++)
		{
			result[i] = 48;
		}
	    for (i = a - 1; i >= 0; i--)  
	    {  
	        int carry = 0;  
	        int n1 = intal1[i] - '0';
	        i_n2 = 0;            
	        for (int j = b - 1; j >= 0; j--)  
	        {  
	            int n2 = intal2[j] - '0';  
	  
	            int sum = n1 * n2 + (result[i_n1 + i_n2]-'0') + carry;  
	            carry = sum / 10;  
	            result[i_n1 + i_n2] = 48+(sum % 10);  
	  
	            i_n2++;  
	        }  
	  
		        if (carry > 0)  
	            result[i_n1 + i_n2] = 48 + result[i_n1+i_n2] - '0' + carry;  
	  
	        i_n1++;  
	    }
	int v = i_n1 + i_n2;
	v--;
	while(result[v] == 48) 
	{
		v--;
	}
	result[v+1] = '\0';
	reversestring(result);
	return result;
}

// Returns intal1 mod intal2
// The mod value should be in the range [0, intal2 - 1].
// intal2 > 1
// Implement a O(log intal1) time taking algorithm.
// O(intal1 / intal2) time taking algorithm may exceed time limit.
// O(intal1 / intal2) algorithm may repeatedly subtract intal2 from intal1.
// That will take intal1/intal2 iterations.
// You need to design a O(log intal1) time taking algorithm.
// Generate your own testcases at https://www.omnicalculator.com/math/modulo
char* intal_mod(const char* intal1, const char* intal2)
{
	
	if(intal_compare(intal1,intal2) == -1)
	{
		char *l = copy(intal1);
		return l;
	}
	int diffbits = strlen(intal1)-strlen(intal2);
	int remobit = (greater(intal1,intal2) == 1)?0:1;
	diffbits -= remobit;
	if(diffbits > 0)
	{
       		char *extended = malloc(sizeof(char)*(strlen(intal2)+diffbits+1));
		for(int i = 0; i < strlen(intal2); i++)
		{
			extended[i]=intal2[i];
		}
		int m = strlen(intal2);
		for(int i = 0; i < diffbits; i++)
		{
			extended[i+m] = 48;
		}
		extended[diffbits+m] = '\0';
		extended = intal_diff(intal1,extended);
		return intal_mod(extended,intal2);
	}
	return intal_mod(intal_diff(intal1,intal2),intal2);
}

// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
// Implement a O(log n) intal multiplications algorithm.
// 2^3000 has less than 1000 decimal digits. 3000 intal multiplications may exceed time limit.
char * intal_pow(const char *intal1,unsigned int n)
{ 
    	if (n == 0)
	{ 
               char *v=malloc(sizeof(char)*2);
		v[1]='\0';
		v[0]=49;
		return v;
	} 
    	else if (n%2 == 0)
	{ 
        	return intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2));
	} 
    	else
	{
       		return intal_multiply(intal1,intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2)));
	} 
} 

// Returns Greatest Common Devisor of intal1 and intal2.
// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.
// Use Euclid's theorem to not exceed the time limit.
char* intal_gcd(const char *intal1, const char *intal2)
{
	if(intal1[0] == 48 && intal2[0] == 48)
	{
		char *result = malloc(sizeof(char)*2);
		result[1] = '\0';
		result[0] = 48;
		return result;
	}

	if(intal2[0] == 48)
	{ 
		char *result = copy(intal1);
		return result;
	}

	else
	{ 
		return intal_gcd(intal2, intal_mod(intal1, intal2));
	}
}

// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".
char* intal_fibonacci(unsigned int n)
{
	if(n == 0 || n == 1)
	{
		char *ans = malloc(sizeof(char)*2);
		ans[1] = '\0';
		if(n == 0)
		{
			ans[0] = 48;
			return ans;
		}
		if(n == 1){
			ans[0] = 49;
			return ans;
		}
	}
	char *res;
	char *fst;
	char *snd;
	fst = malloc(sizeof(char)*2);
	snd = malloc(sizeof(char)*2);
	fst[0] = 48;
	snd[0] = 49;
	fst[1] = '\0';
	snd[1] = '\0';
	while(n-1)
	{
		res = intal_add(fst,snd);
		fst = snd;
		snd = res;
		n--;
	}
	return res;
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n)
{
	if(n==1 || n==0)
	{
		char *result = malloc(sizeof(char)*2);
		result[1] = '\0';
		result[0] = 49;
		return result;
	}
	return intal_multiply(conversion(n),intal_factorial(n-1));
}

// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n,k).
// Use Dynamic Programming. Use extra space of not more than O(k) number of intals. Do not allocate the whole O(nk) DP table.
// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* intal_bincoeff(unsigned int n, unsigned int k)
{	
    	char** bc = malloc(sizeof(char* )*(k+1));
    	for(int i = 0; i <= k; ++i)
	{    	
	bc[i]="0";
	}
    	bc[0]=malloc(sizeof(char)*2);
	bc[0][0]=49;
	bc[0][1]='\0';
    	for(int i = 1; i <= n; ++i)
    	{
		int range = i>k?k:i;
    		for(int j = range; j > 0; --j)
    		{	 
			bc[j] = intal_add(bc[j],bc[j-1]);
        	}
	}
    	char *result = malloc(sizeof(char)*strlen(bc[k]));
    	strcpy(result,bc[k]);
	for(int i=0;i<k+1;i++)
	{
		free(bc[i]);
	}
	free(bc);
    	return result;
}

// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n)
{
    	char *res = arr[0];
    	int index = 0;
    	for(int i = 1; i < n; i++)
	{
        	if(intal_compare(arr[i],res) == 1)
		{
            		index = i;
            		res = arr[i];
        	}
    	}
    	return index;
}

// Returns the offset of the smallest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_min(char **arr, int n)
{
    	char *res = arr[0];
    	int index = 0;
    	for(int i = 1; i<n; i++)
	{
	        if(intal_compare(arr[i],res) == -1)
		{
            		index=i;
            		res=arr[i];
        	}
    	}
    	return index;
}

// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n, char* key)
{
    	int ans = -1;
    	for(int i = 0;i < n; i++)
	{
        	if(isequal(arr[i],key) == 1)
		{
            		ans=i;
            		return ans;
        	}
    	}

    	return ans;
}


static int binarysearch(char **arr, int l, int r, char *key) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        
        if (intal_compare(arr[mid],key)==0){ 
            return mid; }
  
        if (intal_compare(arr[mid],key)==1){ 
            return binarysearch(arr, l, mid - 1, key);} 
  
        return binarysearch(arr, mid + 1, r, key); 
    } 
  
    return -1; 
} 

// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.
int intal_binsearch(char **arr, int n, char* key)
{
    	return binarysearch(arr, 0, n-1, 	key);
}

static void merge(char** arr, int l, int m, int r) 
{ 
    	int i, j, k; 
    	int n1 = m - l + 1; 
    	int n2 =  r - m; 
  
    	char** L = createarray(n1);
    	char** R = createarray(n2); 
    	for (i = 0; i < n1; i++)
	{
        	L[i] = copy(arr[l + i]);
	} 
    	for (j = 0; j < n2; j++)
	{
        	R[j] = copy(arr[m + 1+ j]);
	} 
  
    	i = 0;  
    	j = 0; 
    	k = l;  
    	while (i < n1 && j < n2) 
  	{ 
   		if (intal_compare(L[i],R[j])<=0) 
        	{ 
            		arr[k] = copy(L[i]); 
            		i++; 
        	} 
        	else
        	{ 
            		arr[k] = copy(R[j]); 
            		j++; 
        	} 
        	k++; 
    	} 
  
    	while (i < n1) 
    	{ 
        	arr[k] = copy(L[i]); 
        	i++; 
        	k++; 
    	} 
  
    	while (j < n2) 
    	{ 
        	arr[k] = copy(R[j]); 
        	j++; 
        	k++; 
    	} 
	for(int i = 0; i < n1; i++)
	{
		free(L[i]);
	}
	for(int i = 0; i < n2; i++)
	{
		free(R[i]);
	}
	free(L);
	free(R);
}







static void mergeSort(char** arr, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 

} 

// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.
void intal_sort(char **a, int n){

    mergeSort(a,0,n-1);
}

static char* max(const char *x, const char *y)	
{
	char *l=copy(x);
	char *m=copy(y);
	if(intal_compare(l,m)==1)
	{
        	return l;
    	}
    	else
	{
        	return m;
    	}
}

static char* coins(char** arr, int index, int n)
{
    	if (index == n)
	{
        	return "0";
	}
    	if (index==n-1)
	{
        	return arr[index];
	}
    	if (index==n-2)
	{
        	return max(arr[index],arr[index+1]);
	}
    	return max(intal_add(arr[index],coins(arr,index+2,n)),coins(arr,index+1,n));
}

// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25
char* coin_row_problem(char **arr, int n)
{
    return coins(arr,0,n);
}

