import java.io.File;
import java.io.FilenameFilter;
import java.util.Scanner;


public class 1 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String str;
		str=sc.nextLine();
		File f=new File(str);
		if(!f.exists()){
			System.out.println("文件不存在");
			System.exit(1);
		}
		if(!f.isDirectory()){
			System.out.println("不是目录");
			System.exit(1);
		}
		File file[]=f.listFiles(new FilenameFilter(){
			public boolean accept(File dir,String name){
				return name.endsWith(".txt");
			}
		});
		
		for(int i=0;i<file.length;i++){
			System.out.println(file[i]);
		}
	}

}
