edit distance
lcs

gcd
int gcd(int a,int b)
{
 if(a==0)
  return b;
 if(b==0) return a;
 if(b>a)
  return gcd(b,a);
 if(a%b==0)
  return b;
  return gcd(b,a%b);
}
sort
void quicksort(int x[100000],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

Matrix chain

spoj/mixtures.c

power
a==0 not handled
unsigned long long int ex(unsigned long long int a,unsigned long long int n)
{
  if(n==0)
  return 1;
 if(n==1)
  return a;
  n=n%(MAX-1);
  unsigned long long int y=ex(a,n/2);
  if(n%2==1)
   return (a*((y*y)%MAX))%MAX;
  else
   return (y*y)%MAX;
}


string divide by two

void div(char * res,char *s1)
{
 int divisor=2,tempval=0,currpos=0,currres=0;
 while(tempval<divisor && s1[currpos]!='\0')
 {
  tempval=tempval*10+s1[currpos++]-48;
 }
 while(s1[currpos]!='\0')
 {
  res[currres++]=tempval/divisor+48;
  tempval%=divisor;
  tempval=tempval*10+s1[currpos++]-48;
 }
 res[currres++]=tempval/divisor+48;
 res[currres]='\0';
}
string substraction


void sub(char * res,char *s1,char *s2)
{
 int s1len=0,s2len=0,reslen=0,borr=0,shiftpos;
 for(;s1[s1len]!='\0';s1len++);
 for(;s2[s2len]!='\0';s2len++);
 reslen=s1len>s2len?s1len:s2len;
 //printf("%d",reslen);
 res[reslen--]='\0';
 for(s1len--,s2len--;s1len>=0 && s2len>=0;s1len--,s2len--)
 {
  if(s1[s1len]-borr>=s2[s2len])
   res[reslen--]=s1[s1len]-s2[s2len]-borr+48,borr=0;
  else
  {
   res[reslen--]=s1[s1len]-s2[s2len]-borr+10+48;
   borr=1;
  }
  //printf("%c",res[reslen+1]);
 }
 for(;s1len>=0;s1len--)
 {
  if(s1[s1len]-borr>='0')
   res[reslen--]=s1[s1len]-borr,borr=0;
  else
  {
   res[reslen--]=s1[s1len]-borr+10;
   borr=1;
  }
 // printf("%c",res[reslen+1]);
 }
 reslen++;
 while(res[reslen]=='0')
  reslen++;
 for(shiftpos=0;res[reslen]!='\0';reslen++)
  res[shiftpos++]=res[reslen];
 res[shiftpos]='\0';
 if(shiftpos==0)
 {
  res[shiftpos++]='0';
  res[shiftpos]='\0';
 }
}
int editdistance(char *source,char *dest)
{
 int *p=(int *)malloc(2002*sizeof(int));
 int *q=(int *)malloc(2002*sizeof(int)),*r;
 int j,k,l,sourcelen,destlen,i,val;
 sourcelen=strlen(source);
 destlen=strlen(dest);
 p[0]=0;
 for(i=1;i<=sourcelen;i++) p[i]=i;
 //for(j=1;j<=destlen;j++)   distance[0][j]=j;
 for(i=1;i<=sourcelen;i++)
 {
  for(j=0;j<=destlen;j++)
   {
	   if(j==0)
	   {
		   q[j]=i;
		   continue;
	   }
//zero cost if both letters same
   if(source[i-1]==dest[j-1])
	 val=0;
	else
	 val=1;
	q[j]=min(p[j-1]+val,min(p[j]+1,q[j-1]+1));
   }
   r=q,q=p,p=r;
  }
   return p[destlen];
}


void sum (char *res,char * s1,char *s2)
{
	int i,j,k,carry;
	for(i=0;s1[i]!='\0';i++);
	for(j=0;s2[j]!='\0';j++);
	k=(i>j)?i+1:j+1;
	res[k]='\0';
	for(i--,j--,k--,carry=0;i>=0 && j>=0;i--,j--,k--)
	{
		res[k]=((s1[i]+s2[j]-96+carry)%10)+48;
		carry=(s1[i]+s2[j]-96+carry)/10;
		//printf("%c",res[k]);
	}
	//printf("b%da%sc",k,res);
	if(carry)
		res[k]=carry+48;
	else
	{
		k=1;
		for(i=0;res[k]!='\0';i++,k++)
			res[i]=res[k];
		res[i]=res[k];
	}
}

segtree

int seg[500001];
void create(int s,int e,int index){
  if(s==e){
    //seg[index]=lp[x];
    //single node
    return;
  }
  int mid=(s+e)/2;
  create(s,mid,2*index);
  create(mid+1,e,2*index+1);
 // seg[index]=maxim(seg[2*index],seg[2*index+1]);//maxim(seg[index*2].max,seg[index*2+1].max);
 //parent node
}
int get(int l,int r,int s,int e,int index){
  if(e<l || r<s)
    return 1;
  if(l<=s && r>=e){
    return seg[index];
  }
  int mid=(s+e)/2;
  return maxim(get(l,r,s,mid,index*2),get(l,r,mid+1,e,index*2+1));
}
int update(int l,int r,int s,int e,int index){
  if(e<l || r<s)
    return -1;
  //cout<<s<<" "<<e<<" "<<index<<endl;
  if(l<=s && r>=e){
    if(seg[index]==1)
      return 1;   //return what if outside
  }
  if(s==e){
    //update single node
    //a[s]=a[s]/seg[index];
    //seg[index]=lp[a[s]];
    return seg[index];
  }
  int mid=(s+e)/2;
  int x=update(l,r,s,mid,index*2),y;
  y=update(l,r,mid+1,e,index*2+1);
//update parent
  //seg[index]= maxim(seg[index*2],seg[index*2+1]);
  return seg[index];
}

hld segtree

#define maxsize 100001
int par[maxsize];
long long int seg[maxsize*10];
int head[maxsize],chainlen[maxsize],chainpos[maxsize];
vector<int> adjl[maxsize];
vector<pair<int,int> > ticket[maxsize];
int segstart[maxsize];
int n,m;
int size[maxsize],heavy[maxsize];
int len;
//int chain[maxsize];
//vector<int> chainset[maxsize];
long long int findleft(long long int a,long long int b){
  return a>b?b:a;
}
int maxs(int n){
  int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
   return 2*(int)pow(2, x) - 1; 
}
int dfs(int i){
  size[i]=1;
  heavy[i]=-1;
  vector<int>::iterator it=adjl[i].begin();
  for(;it!=adjl[i].end();it++){
    size[i]+=dfs(*it);
    if(heavy[i]==-1 || size[heavy[i]]<size[*it])
      heavy[i]=*it;
  }
  return size[i];
}
void create(int s,int e,int index,int sh){
  if(s==e){
    //if(s!=0)
    seg[index+sh]=LLONG_MAX;
    return;
  }
  int mid=(s+e)/2;
  create(s,mid,2*index,sh);
  create(mid+1,e,2*index+1,sh);
  seg[index+sh]=LLONG_MAX;
//  seg[index]=findleft(seg[2*index],seg[2*index+1]);//maxim(seg[index*2].max,seg[index*2+1].max);
}
void print1seg(int s,int e,int index){
  if(s==e){
    cout<<s<<" "<<e<<" "<<seg[index]<<endl;
    return;
  }
  int mid=(s+e)/2;
  print1seg(s,mid,2*index);
  print1seg(mid+1,e,2*index+1);
  cout<<s<<" "<<e<<" "<<seg[index]<<endl;
}
void printseg(){
  int i;
  for(i=0;i<n;i++)
    if(head[i]==i){
      cout<<"Segment Tree\n";
      print1seg(0,chainlen[i]-1,segstart[i]);
    }
}/*
void print(){
  int i;
  cout<<"parent ";
  for(i=0;i<n;i++)
    cout<<par[i]<<" ";
  cout<<endl;
  cout<<"chainlen ";
  for(i=0;i<n;i++)
    cout<<chainlen[i]<<" ";
  cout<<endl;
  cout<<"head ";
  for(i=0;i<n;i++)
    cout<<head[i]<<" ";
  cout<<endl;
  cout<<"chainpos ";
  for(i=0;i<n;i++)
    cout<<chainpos[i]<<" ";
  cout<<endl;
  cout<<"size ";
  for(i=0;i<n;i++)
    cout<<size[i]<<" ";
  cout<<endl;
  cout<<"heavy ";
  for(i=0;i<n;i++)
    cout<<heavy[i]<<" ";
  cout<<endl;
  printseg();
}
*/
 
void createhld(){
  memset(heavy, -1, sizeof(heavy));
  dfs(0);
  int i,j,k;
  len=0;
  int s=0;
  for(i=0;i<n;i++){
    if(par[i]==-1 || i!=heavy[par[i]]){
      for(j=i,k=0;j!=-1;j=heavy[j],k++){
        //chain[j]=len;
        head[j]=i,chainpos[j]=k;//,chainset[len].push_back(j);
      }
      chainlen[i]=k;
      segstart[i]=s;
      create(0,k-1,1,s);      
      len++;
      s+=maxs(chainlen[i])+1;
    }
    
  }
}
 
long long int get(int l,int r,int s,int e,int index,int sh){
  if(e<l || r<s)
    return LLONG_MAX;
  if(l<=s && r>=e){
    return seg[index+sh];
  }
  int mid=(s+e)/2;
  return findleft(get(l,r,s,mid,index*2,sh),get(l,r,mid+1,e,index*2+1,sh));
}
long long int update(int l,long long int v,int s,int e,int index,int sh){
  if(e<l || l<s)
    return LLONG_MAX;
  //cout<<s<<" "<<e<<" "<<index<<endl;
  if(s==e){
    seg[index+sh]=v;
    return seg[index+sh];
  }
  int mid=(s+e)/2;
  if(l<=mid)
    update(l,v,s,mid,index*2,sh);
  else
    update(l,v,mid+1,e,index*2+1,sh);
  seg[index+sh]= findleft(seg[index*2+sh],seg[index*2+1+sh]);
  return seg[index+sh];
}
long long int best[maxsize];
long long int findpar(int i,int k){
  long long int min=LLONG_MAX;
  while(chainpos[i]<k && k>0){
    k-=chainpos[i];
    min=findleft(min,get(0,chainpos[i],0,chainlen[head[i]]-1,1,segstart[head[i]]));
    k--;
    i=par[head[i]];
    if(i==-1)
      break;
  }
  if(i==-1)
    return 0;
  if(k==0)
    return findleft(min,best[i]);
  //cout<<"call "<<chainpos[i]-k<<" "<<chainpos[i]-1<<" "<<0<<" "<<chainlen[head[i]]-1<<endl;
  return findleft(min,get(chainpos[i]-k,chainpos[i],0,chainlen[head[i]]-1,1,segstart[head[i]]));
}
void calcbest(){
  vector<int>::iterator it;
  int q[maxsize],ql=0,i,k=0;
  long long int j=0;
  q[ql++]=0;
  while(k<ql){
    i=q[k];
    it=adjl[i].begin();
    for(;it!=adjl[i].end();it++){
      q[ql++]=*it;
    } 
    //cout<<"Node "<<i<<endl;
    long long int mbest=LLONG_MAX;
    for(vector<pair<int,int> >::iterator tit=ticket[i].begin();tit!=ticket[i].end();tit++){
      j=findpar(i,tit->second);
    //  cout<<"J "<<j<<" "<<tit->second<<" "<<tit->first<<endl;
      j+=tit->first;
      mbest=findleft(mbest,j);
    }
    if(i!=0){
      best[i]=mbest;
      update(chainpos[i],mbest,0,chainlen[head[i]]-1,1,segstart[head[i]]);
    }   
    //cout<<"Best:"<<best[i]<<endl;
    k++;
  }
}