OUT := 205IQ
BUILD_OUT := iq

all: $(OUT)

re: fclean all

$(OUT):
	cargo build --profile=release
	ln -fs target/release/$(BUILD_OUT) $(OUT)

clean:
	cargo clean

fclean: clean
	rm -f $(OUT)

.PHONY: all re clean fclean $(OUT)
