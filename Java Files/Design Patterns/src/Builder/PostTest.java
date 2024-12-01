package Builder;

public class PostTest {
  public static void main(String... args) {
    Post.Builder postBuilder = new Post.Builder();
    postBuilder.title("To the world")
        .text("Hello")
        .category("Public")
        .build();
  }
}
