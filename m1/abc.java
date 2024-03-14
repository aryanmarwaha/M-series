import java.util.*;

// public class abc{
// 	public static void merge(int[]arr,int s,int e,int mid){
// 		int lsize=mid-s+1;
// 		int rsize=e-mid;
// 		int []left=new int[lsize];
// 		int []right=new int[rsize];

// 		int k=0;

// 		for(int i=s;i<=mid;i++){
// 			left[k++]=arr[i];
// 		}
// 		k=0;
// 		for(int i=mid+1;i<=e;i++){
// 			right[k++]=arr[i];
// 		}

// 		int i=0;
// 		int j=0;
// 		int idx=s;

// 		while(i<lsize && j<rsize){
// 			if(left[i]<right[j]) arr[idx++]=left[i++];
// 			else arr[idx++]=right[j++];
// 		}

// 		while(i<lsize){
// 			arr[idx++]=left[i++];
// 		}

// 		while(j<rsize){
// 			arr[idx++]=right[j++];
// 		}
// 	}
// 	public static void sort(int []arr,int s,int e){
// 		if(s>=e) return;
// 		int mid=(s+e)/2;
// 		sort(arr,s,mid);
// 		sort(arr,mid+1,e);

// 		merge(arr,s,e,mid);
// 	}
// 	public static void main(String[] args){
// 		Scanner sc=new Scanner(System.in);
// 		int n=sc.nextInt();
// 		int[] arr=new int[n];

// 		for(int i=0;i<n;i++){
// 			arr[i]=sc.nextInt();
// 		}
// 		// Arrays.sort(arr);
// 		sort(arr,0,n-1);
// 		for(int i=0;i<n;i++){
// 			System.out.print(arr[i]+" ");
// 		}
// 	}
// };


class A{
	int x=10;
	A(){
		x+=5;
	}
};
class B extends A {
	B(){
		x+=3;
	}
};

public class abc{
	public static void main(String args[]){
		B b = new B();
		System.out.println(b.x);
	}
}