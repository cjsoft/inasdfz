#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxN 2010

struct segment
{
	int l,r;
};

int cmp1(const void *a,const void *b)
{
	segment *aa=(segment *)a;
	segment *bb=(segment *)b;
	if (aa->l<bb->l||(aa->l==bb->l&&aa->r<bb->r))
	    return -1;
	else
	    return 1;
}

int cmp2(const void *a,const void *b)
{
	segment *aa=(segment *)a;
	segment *bb=(segment *)b;
	if (aa->r>bb->r||(aa->r==bb->r&&aa->l>bb->l))
	    return -1;
	else
	    return 1;
}

int main()
{
    freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (;t>0;t--)
	{
		int n;
		scanf("%d",&n);
		int is[MaxN][2];
		memset(is,-1,sizeof(is));
		int in=0,out=0,count=0,s_o_l=0,s_i_l=0,l_o=0;
		bool p_in[MaxN>>1],p_out[MaxN>>1];
		segment s_in[MaxN>>1],s_out[MaxN>>1];
		memset(p_in,false,sizeof(p_in));
		memset(p_out,false,sizeof(p_in));
		bool f=true;
		for (int i=1;i<=n;i++)
		{
			char ch;
			ch=getchar();
			while (ch!='E'&&ch!='L')
			      ch=getchar();
			int id;
		    scanf("%d",&id);
		    if (id==0)
		    {
		    	if (ch=='E')
		    	{
		    	    in++;
		    	    l_o++;
		    	    s_out[l_o].l=i;
		    	    s_out[l_o].r=n+1;
		    	    p_in[i]=true;
		        }
		    	else
		    	{
		    	    out++;
		    	    p_out[i]=true;
		        }
		    }
		    else
		    {
		    	if (ch=='E')
		    	{
		    		if (is[id][0]<1)
		    		    is[id][0]=1;
		    		else
		    		{
		    			if (out)
		    			{
		    			    out--;
		    			    l_o++;
		    			    s_o_l++;
		    			    s_out[l_o].l=is[id][1];
		    			    s_out[l_o].r=i;
		    		    }
		    			else
		    			    f=false;
		    		}
		    		is[id][1]=i;
		    	}
		    	else
		    	{
		    		if (is[id][0]==-1)
		    	    {
		    	    	if (in)
		    	    	{
		    	    	    s_i_l++;
		    	    	    s_in[s_i_l].l=0;
		    	    	    s_in[s_i_l].r=i;
		    	        }
		    	    	is[id][0]=0;
		    	    }
		    	    else
		    	    if (is[id][0]==0)
		    	    {
		    	    	if (in)
		    	    	{
		    	    	    in--;
		    	    	    s_i_l++;
		    	    	    s_in[s_i_l].l=is[id][1];
		    	    	    s_in[s_i_l].r=i;
		    	        }
		    	    	else
						    f=false;  
		    	    }
		    	    else
		    	        is[id][0]=0;
		    	    is[id][1]=i;
		    	}
		    }
		}
		if (!f)
		    printf("OTHER\n");
		else
		{
			for (int i=1;i<MaxN;i++)
			    if (is[i][0]==1)
			    {
			    	l_o++;
			    	s_out[l_o].l=is[i][1];
			    	s_out[l_o].r=n+1;
			    }
			qsort(s_in+1,s_i_l,sizeof(s_in[1]),cmp1);
			qsort(s_out+1,l_o,sizeof(s_out[1]),cmp2);
			int l=1;
			while (l<s_i_l&&s_in[l].l==0)
			      l++;
			if (s_i_l==0)
			   l=0;
			bool pp_in[MaxN>>1];
		    int L=1,R=l;
		    int m;
		    for (;L<=R;)
		    {
		    	m=(L+R)>>1;
		    	for (int i=0;i<MaxN;i++)
		    	    pp_in[i]=p_in[i];
		    	bool mark=true;
		    	for (int i=m;i<=s_i_l;i++)
		    	{
		    		mark=false;
		    	    for (int j=s_in[i].l;j<=s_in[i].r;j++)
		    	        if (pp_in[j])
		    	        {
		    	        	pp_in[j]=false;
		    	        	mark=true;
		    	        	break;
		    	        }
		    	    if (!mark)
		    	    {
		    	        if (m==l)
						   f=false;
		    	        break;
		    	    }
		        }
		        if (!mark)
		            L=m+1;
		        else
		            R=m-1;
		    }
		    if (f)
		    {
		    	bool pp_out[MaxN>>1];
		        int L=1;
		        int R=l_o-s_o_l+1;
		        int m;
		        int M=0;
		        for (;L<=R;)
		        {
		        	m=(L+R)>>1;
		        	bool mark=true;
		        	for (int i=0;i<MaxN;i++)
		    	    	pp_out[i]=p_out[i];
		    		for (int i=m;i<=l_o;i++)
		   			{
		   				mark=false;
		   	    		for (int j=s_out[i].r;j>=s_out[i].l;j--)
		        			if (pp_out[j])
		        			{
	   	        				pp_out[j]=false;
	   	        				mark=true;
	    	        			break;
	    	    			}
		    			if (!mark)
		    			{	
		    	    		if (m==l_o-s_o_l+1)
						   		f=false;
		    	    		break;
		    			}
		    		}
		    		if (!mark)
		    		    L=m+1;
		    		else
		    		    R=m-1;
		    	}
		    	if (f)
		    	{
		    		int ans=m-s_o_l-1;
					printf("%d\n",ans);
		    	}
		    	else
		    		printf("OTHER\n");
		    }
		    else
		        printf("OTHER\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
}
