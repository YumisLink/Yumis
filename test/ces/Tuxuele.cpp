class A {
 public virtual Shit() {}
 public update() { Shit(); }
}

class B : A {
 public
  virtual Shit() { Console.WriteLine("?"); }
}

B k;
k.update();
