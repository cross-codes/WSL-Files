public class Main {
  public static void main(String[] args) {
    Person ada = new Person("Ada");

    Whistle duckWhistle = new Whistle("Kvaak");
    Whistle roosterWhistle = new Whistle("Peef");

    duckWhistle.sound();
    roosterWhistle.sound();
    duckWhistle.sound();

    ada.growOlder();
    ada.growOlder();

    Person pekka = new Person("Pekka");

    pekka.growOlder();
    System.out.println("Pekka's age: " + pekka.returnAge());

    System.out.println(pekka.isOfLegalAge());
  }
}
