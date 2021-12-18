package interpreteur;

public class Main {
    public static void main(String[] args) {
        Expression e1 = new Somme(new Nombre(1), new Nombre(2));
        Expression e2 = new Difference(new Nombre(2), new Nombre(1));
        Expression e3 = new Division(new Nombre(10), new Nombre(5));
        Expression e4 = new Produit(new Nombre(20), new Nombre(4));
        Expression e5 = new SommeMultiple(new Nombre(20), new Nombre(4),new Nombre(1), new Nombre(2));
        Expression e6 = new Moyenne(new Nombre(20), new Nombre(4),new Nombre(1), new Nombre(2));
        Expression e7 = new Moyenne(e1,e2,e3,e4,e5,e6);
        System.out.println(e1);
        System.out.println(e1.toStringPrefix());
        System.out.println(e1.toStringPostfix() + "\n");
        System.out.println(e2);
        System.out.println(e2.toStringPrefix());
        System.out.println(e2.toStringPostfix() + "\n");
        System.out.println(e3);
        System.out.println(e3.toStringPrefix());
        System.out.println(e3.toStringPostfix() + "\n");
        System.out.println(e4);
        System.out.println(e4.toStringPrefix());
        System.out.println(e4.toStringPostfix() + "\n");
        System.out.println(e5);
        System.out.println(e5.toStringPrefix());
        System.out.println(e5.toStringPostfix());
        System.out.println("Il y a : " + e5.nombreNombre() + " nombres.\n");
        System.out.println(e6);
        System.out.println(e6.toStringPrefix());
        System.out.println(e6.toStringPostfix());
        System.out.println("Il y a : " + e6.nombreNombre() + " nombres.\n");
        System.out.println(e7);
        System.out.println(e7.toStringPrefix());
        System.out.println(e7.toStringPostfix());
        System.out.println("Il y a : " + e7.nombreNombre() + " nombres.\n");
    }
}
