package visiteur;

public interface Expression {
    int valeur();

    Object accept(Visiteur v);
}
