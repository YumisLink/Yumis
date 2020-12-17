import java.io.File;
import java.io.FilenameFilter;
class Files implements FilenameFilter{

	@Override
	public boolean accept(File dir, String name) {
		if(dir.isDirectory()) 
      return true;
    return false;
	}
  
}
public class test1{
	public static void main(String[] args) {
    File file=new File("D:\\");
		File file1[]=file.listFiles(new Files());
		System.out.println(file1.length);
	}
}
