package Builder;

import java.util.function.BiConsumer;
import java.util.function.Supplier;

public class GenericBuilder<T> {
  private final Supplier<T> supplier;

  private GenericBuilder(Supplier<T> supplier) {
    this.supplier = supplier;
  }

  public static <T> GenericBuilder<T> of(Supplier<T> supplier) {
    return new GenericBuilder<>(supplier);
  }

  public <U> GenericBuilder<T> with(BiConsumer<T, U> consumer, U value) {
    return new GenericBuilder<>(() -> {
      T object = supplier.get();
      consumer.accept(object, value);
      return object;
    });
  }

  public T build() {
    return supplier.get();
  }
}
