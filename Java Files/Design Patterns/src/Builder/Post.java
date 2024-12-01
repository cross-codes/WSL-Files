package Builder;

public class Post {
  private final String title;
  private final String text;
  private final String category;

  private Post(Builder builder) {
    this.title = builder.title;
    this.text = builder.text;
    this.category = builder.category;
  }

  public String getTitle() {
    return this.title;
  }

  public String getText() {
    return this.text;
  }

  public String getCategory() {
    return this.category;
  }

  public static class Builder {
    private String title;
    private String text;
    private String category;

    public Builder() {
    }

    public Builder title(String title) {
      this.title = title;
      return this;
    }

    public Builder text(String text) {
      this.text = text;
      return this;
    }

    public Builder category(String category) {
      this.category = category;
      return this;
    }

    public Post build() {
      return new Post(this);
    }
  }
}
