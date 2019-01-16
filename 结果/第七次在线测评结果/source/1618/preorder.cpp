 #include<cstdio>
 #include<cstring>
 void build(int n,char*s1,char*s2,char*s)  {
      if(n<=0)return;
     int p=strchr(s1,s2[n-1])-s1;
     //strchr(string , char )函数
//功能：查找字符串s1中首次出现字符s1[n-1]的位置
   //说明：返回首次出现s2[n-1]的位置的指针，如果s2中不存在c则返回NULL.
    s[0]=s2[n-1];
    build(p+1,s1,s2,s+1);
    build(n-p,s1+p+1,s2+p,s+p+1);     //重建左子树和右子树

     //要得到先序遍历,所以整个的第一个是根
}
 int main()
 {
     freopen("preorder.in","r",stdin);
     freopen("preorder.out","w",stdout);
     char s1[11],s2[11],ans[11];
     memset(s1,0,sizeof(s1));
     memset(s2,0,sizeof(s2));
     while(scanf("%s %s",s1,s2)!=EOF)
    {         int n=strlen(s1);
        // for(int i=0;i<n;i++)
         //if()

         build(n,s1,s2,ans);
         ans[n]='\0';
         printf("%s\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
return 0;
 }
