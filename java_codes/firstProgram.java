class firstProgram{

public static void main(String arg[]){
	System.out.println("Hello world");
	int num=100;
	System.out.println("value of num is:"+num*2);
    double area;
    int r=10;
    double pi=3.14;
	area=pi*r*r;
	System.out.println("Area is :"+area);
	
	char ca,cb;
	ca=88;
	cb='Y';                                            // MUST BE IN SINGLE QUOTE
	System.out.println("ca and cb are :"+ca+" "+cb);
	cb++;
	ca++;
	System.out.println("ca and cb are :"+ca+" "+cb);    //Char can be increamented and decremented
														//just like an integer
														
	//int array1[]=new int[12];
	//array1=new int[12];
	
	//int[] a1=new int[3];
	//int a1[]=new int[3];  both are same
	//int[] a1,a2,a3; = int a1[],int a2[], int a3[];
	int array1[]={1,2,3,4,5};
	System.out.println(array1[1]);
	
	///multi dimention array can have different number of columns for each row
	int mda[][]=new int[4][];
	mda[0]=new int[5];
	mda[1]=new int[4];
	mda[2]=new int[3];
	mda[3]=new int[2];
	int newArray[][]={
		{1,2,3},{4,5,6},{7,8,9}
	};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			System.out.println("newArray["+i+"]["+j+"] is:"+newArray[i][j]);
		}
	}		
	
}
}