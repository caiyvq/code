for(i=2; i<=c1&&i<=c2; i++)//c1为分子，c2为分母 
{
    if(c1%i==0&&c2%i==0)
  {
    c1=c1/i;//判断i是否为公约数 
    c2=c2/i;
    i--;
  }
}
	
