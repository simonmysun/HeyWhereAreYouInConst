#include<stdio.h>
#include<string.h>

#define MOD 4009

void init(void);

int strq[32];
	int hash;
	int qstart;
	int getnext(int k);
	void push(int x);
	int gethash(void);

int mystr[32];
int mylen;
int myhash;
int loc;
int k;

void check(void);

int main(int argc,char *argv[])
{
	init();

	mylen=strlen(argv[1]);
	for(int i=0;i<mylen;i++)
	{
		mystr[i]=argv[1][i];
		myhash+=argv[1][i]*argv[1][i];
		myhash%=MOD;
	}

/*
	char tmpstr[6]="23536";
	mylen=5;
	for(int i=0;i<mylen;i++)
	{
		mystr[i]=tmpstr[i];
		myhash+=tmpstr[i]*tmpstr[i];
		myhash%=MOD;
	}
*/
    FILE *fp;
    char buffer[2];
    fp = fopen("dat/pi", "r");

	for(int i=1;i<=mylen;i++)
	{
		fgets(buffer, sizeof(buffer), fp);
		push(buffer[0]);
		//printf("%s",buffer);
		loc++;
	}
	check();
    if (fp != NULL)
    {
        while (fgets(buffer, sizeof(buffer), fp) != NULL)
        {
			push(buffer[0]);
			//printf("%s",buffer);
			loc++;
			check();
        }
    }
	if(k==0)
	{
		printf("Sorry, none is found. \n");
	}
    fclose(fp);
    return 0;
}

void init(void)
{
	loc=0;
	qstart=0;
	hash=0;
	k=0;

	for(int i=0;i<32;i++)
	{
		strq[i]=0;
	}
}

int getnext(int k)
{
	return (k+1)%mylen;
}

void push(int x)
{
	hash=hash-strq[qstart]*strq[qstart]+x*x;
	hash=hash+MOD;
	hash%=MOD;
	strq[qstart]=x;
	qstart=getnext(qstart);
}

int gethash(void)
{
	return hash;
}

void check(void)
{
	if(gethash()==myhash)
	{
		int flag=1;
		for(int i=qstart;getnext(i)!=qstart;i=getnext(i))
		{
			if(mystr[i-qstart]!=strq[i])
			{
				flag=0;
				return;
			}
		}
		if(flag==1)
		{
			k++;
			printf("No.%d: %d~%d\n",k,loc-mylen+1,loc);
			if(k>=32)
			{
				printf("Too many. \n");
				exit(0);
			}
		}
	}
}

