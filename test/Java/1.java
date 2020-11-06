abstract class Employee {
    protected double salary;

    public Employee(double salary) {
        this.salary = salary;
    }

    abstract double computeSalary();
}

class Manager extends Employee {
    public Manager(double salary) {
        super(salary);
    }

    double computeSalary() {
        return salary * 10;
    }
}

class Salesman extends Employee {
    private double up;

    public Salesman(double salary) {
        super(salary);
    }

    double computeSalary() {
        return salary * 2;
    }
}

class Worker extends Employee {
    private double day;

    public Worker(double salary) {
        super(salary);
    }

    double computeSalary() {
        return salary * 1;
    }
}

public class Test3 {
    public static void main(String[] args) {
        Employee manager = new Manager(10000);
        Employee sal = new Salesman(10000);
        Employee wo = new Worker(1000);
        System.out.println(manager.computeSalary());
        System.out.println(sal.computeSalary());
        System.out.println(wo.computeSalary());
    }
}
