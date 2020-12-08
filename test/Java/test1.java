import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;
import java.util.jar.Attributes.Name;

class PersonSortable2{
	private String name;
	private int age;
	public String getName() {
		return name;
	}
	public int getAge() {
		return age;
	}
	PersonSortable2(String ss, int ii)
	{
		name = ss;
		age = ii;
	}
	public String toString() {
		return name + "-" + age;
	}
	public int compareTo(PersonSortable2 o) {
		return name.compareTo(o.name) == 0 ? (age == o.age ? 0 : (age < o.age ? -1 : 1) ): name.compareTo(o.name);
	}
}

class NameComparator extends PersonSortable2 implements Comparable<NameComparator>{
	NameComparator(String ss, int ii) {
		super(ss, ii);
	}
	public int compareTo(NameComparator o) {
		return getName().compareTo(o.getName());
	}
}
class AgeComparator extends PersonSortable2 implements Comparable<AgeComparator>{
	AgeComparator(String ss, int ii) {
		super(ss, ii);
	}
	public int compareTo(AgeComparator o) {
		return getAge() == o.getAge() ? 0 : (getAge() < o.getAge() ? -1 : 1) ;
	}
}
public class test1 {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		NameComparator ps2[] = new NameComparator[n];
		AgeComparator ps3[] = new AgeComparator[n];
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			int a = sc.nextInt();
			ps2[i] = new NameComparator(s,a);
			ps3[i] = new AgeComparator(s,a);
		}

		System.out.println("NameComparator:sort");
		Arrays.sort(ps2);
		for (int i = 0; i < n; i++) {
			System.out.println(ps2[i].toString());
		}

		System.out.println("AgeComparator:sort");
		Arrays.sort(ps3);
		for (int i = 0; i < n; i++) {
			System.out.println(ps3[i].toString());
		}
	}

}
