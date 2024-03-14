import java.util.*;
public class hello{
	public static void question_2(){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		String[] arr = new String[n];

		for(int i=0;i<n;i++){
			arr[i]= sc.next();
		}
		String str = sc.next();

		for(int i=0;i<n;i++){
			if(arr[i].compareTo(str) > 0){
				System.out.print(arr[i]+" ");
			}
		}
	}

	public static void question_7(){
		Scanner sc = new Scanner(System.in);

		String str = sc.nextLine();
		str = str.replaceAll(" ","");
		System.out.println(str);
	}
	public static void question_9(){
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();

		String target = sc.next();
		ArrayList <Integer>res = new ArrayList<>();
		
		for(int i=0;i<str.length()-target.length();i++){
			if(str.substring(i,i+target.length()).equals(target)) res.add(i);
		}
		System.out.println(res);
	}
	public static void question_1_1(){
		Scanner sc = new Scanner(System.in);
		try{
			String str = sc.nextLine();
			for(int i=0;i<str.length();i++){
				if((str.charAt(i)>'z' || str.charAt(i)<'a')){
					throw new Exception("yo");
				}
			}
		}
		catch (Exception e){
			System.out.println("Invalid Name");
			return;
		}

		try{
			int id = sc.nextInt();
			if(id<=0){
				throw new Exception("yo");
			}
		}
		catch (Exception e){
			System.out.println("Invalid Id");
			return;
		}

		try{
			int sal = sc.nextInt();
			if(sal<0){
				throw new Exception("yo");
			}
		}
		catch (Exception e){
			System.out.println("Invalid Salary");
			return;
		}
	}
	
	public static void question_60(){
		Scanner sc = new Scanner(System.in);
		int n= sc.nextInt();
		int m= sc.nextInt();

		int k=0;
		for(int i=0;i<n-1;k++){
			if((3*k+2)%m!=0 && (3*k+2)>n){
				System.out.println(3*k+2);
				i++;
			}
		}
	}

	public static void question_61(){
		Scanner sc = new Scanner(System.in);
		StringBuffer str = new StringBuffer(sc.next());
		StringBuffer prev = new StringBuffer(str);
		int count=0;

		while(str.compareTo(prev)!=0){
			prev= new StringBuffer(str);
			int index =-1;
			for(int i=0;i<str.length()-1;i++){
				index = str.indexOf("10",i);
				if(index!=-1) break;
			}
			if(index!=-1){
				prev = new StringBuffer(str);
				str.delete(index,index+2);
				count++;
				continue;
			}
			// index = indexOf("00",str);
			for(int i=0;i<str.length()-1;i++){
				index = str.indexOf("00",i);
				if(index!=-1) break;
			}
			if(index!=-1){
				prev = new StringBuffer(str);
				str.delete(index,index+2);
				count++;
				continue;
			}
		}
		System.out.println(str.length());
	}

	public static void question_63(){
		// Scanner sc = new Scanner(System.in);
		// int a = sc.nextInt();
		// int b = sc.nextInt();
		// while()
	}
	public static boolean check_palindrome(String str){
		for(int i=0;i<str.length()/2;i++){
			if(str.charAt(i)!=str.charAt(str.length()-i-1)){
				return false;
			}
		}
		return true;
	}
	public static void question_67(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt()+1;
		String bin = Integer.toBinaryString(n);
		while(!check_palindrome(bin)){
			n++;
			bin = Integer.toBinaryString(n);
		}
		System.out.println(n);
	}
	public static void question_69_helper(ArrayList<Integer> arr,ArrayList<Integer> curr, int i){
		if(i>=arr.size()){
			return;
		}
		int sum=0;
		for(int j=0;j<curr.size();j++){
			sum+=curr.get(j);
		}
		if(sum==0 && curr.size()>0) System.out.println(curr);

		curr.add(arr.get(i));
		question_69_helper(arr,curr,i+1);
		curr.remove(curr.size()-1);
		question_69_helper(arr,curr,i+1);
	}
	public static void question_69(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> arr = new ArrayList<>();

		for(int i=0;i<n;i++){
			arr.add(sc.nextInt());
		}
		ArrayList<Integer> curr = new ArrayList<>(); 
		question_69_helper(arr,curr,0);
	}
	public static void question_70_helper(StringBuilder str, int i, StringBuilder res, HashSet<String> hst){
		if(i>=str.length()){
			return;
		}
		// not pick
		if(!hst.contains(res+"")){
			System.out.println(res);
			hst.add(res+"");
		}
		question_70_helper(str,i+1,res,hst);
		
		//pick
		res.append(str.charAt(i));
		if(!hst.contains(res+"")){
			System.out.println(res);
			hst.add(res+"");
		}
		question_70_helper(str,i+1,res,hst);
		res.deleteCharAt(res.length()-1);

	}
	public static void question_70(){
		Scanner sc = new Scanner(System.in);
		StringBuilder str = new StringBuilder(sc.next());
		StringBuilder res = new StringBuilder("");
		HashSet<String> hst = new HashSet<>();
		question_70_helper(str,0,res,hst);
	}
	public static void question_70_1_(){
		Scanner sc = new Scanner(System.in);
		// Scanner sc1 = new Scanner(System.in);
		
		int n = sc.nextInt();
		sc.next();
		ArrayList<String> data = new ArrayList<>();
		for(int i=1;i<=n;i++){
			String str = sc.nextLine();
			data.add(str);
		}
		String target = sc.next();
		for(int i=0;i<n;i++){
			String[] arr = data.get(i).split(" ");
			if(arr[0].equals(target)){
				System.out.println(arr[0]);
				System.out.println(arr[1]);
				System.out.println(arr[2]);
				return;
			}
		}
		System.out.println(-1);
	}
	public static void main(String[] args){
		question_70_1_();
	}
}