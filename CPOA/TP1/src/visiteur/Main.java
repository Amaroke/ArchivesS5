package visiteur;

public class Main {
    public static void main(String[] args) {
        VisitToString visit = new VisitToString();
        VisitToPrefix prefix = new VisitToPrefix();
        VisitToPostfix postfix = new VisitToPostfix();
        VisitToNombreDeNombre nombreDeNombre = new VisitToNombreDeNombre();
        Expression e1 = new Somme(new Nombre(1), new Nombre(2));
        Expression e2 = new Difference(new Nombre(2), new Nombre(1));
        Expression e3 = new Division(new Nombre(10), new Nombre(5));
        Expression e4 = new Produit(new Nombre(20), new Nombre(4));
        Expression e5 = new SommeMultiple(new Nombre(20), new Nombre(4),new Nombre(1), new Nombre(2));
        Expression e6 = new Moyenne(new Nombre(20), new Nombre(4),new Nombre(1), new Nombre(2));
        Expression e7 = new Moyenne(e1,e2,e3,e4,e5,e6);
        System.out.println(e1.accept(visit));
        System.out.println(e1.accept(prefix));
        System.out.println(e1.accept(postfix) + "\n");
        System.out.println(e2.accept(visit));
        System.out.println(e2.accept(prefix));
        System.out.println(e2.accept(postfix) + "\n");
        System.out.println(e3.accept(visit));
        System.out.println(e3.accept(prefix));
        System.out.println(e3.accept(postfix) + "\n");
        System.out.println(e4.accept(visit));
        System.out.println(e4.accept(prefix));
        System.out.println(e4.accept(postfix) + "\n");
        System.out.println(e5.accept(visit));
        System.out.println(e5.accept(prefix));
        System.out.println(e5.accept(postfix));
        System.out.println("Il y a : " + e5.accept(nombreDeNombre) + " nombres.\n");
        System.out.println(e6.accept(visit));
        System.out.println(e6.accept(prefix));
        System.out.println(e6.accept(postfix));
        System.out.println("Il y a : " + e6.accept(nombreDeNombre) + " nombres.\n");
        System.out.println(e7.accept(visit));
        System.out.println(e7.accept(prefix));
        System.out.println(e7.accept(postfix));
        System.out.println("Il y a : " + e7.accept(nombreDeNombre) + " nombres.\n");
    }
}
