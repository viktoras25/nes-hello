BUILD_DIR	= ./build
PLATFORM	= nes
CA65		= ca65 -t $(PLATFORM)
LD65		= ld65 -t $(PLATFORM)

OBJECTS		= main.o
TARGET		= main.nes

## Build

all: build_dir $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD65) $(BUILD_DIR)/$^ -o $(BUILD_DIR)/$(TARGET)

%.o: %.asm
	$(CA65) $< -o $(BUILD_DIR)/$@

build_dir:
	mkdir -p $(BUILD_DIR)

## Helpful scripts

compile:
	docker run --rm -it -v ${PWD}:/app -w /app viktoras25/cc65:latest make

clean:
	rm -rf $(BUILD_DIR)

run:
	fceux $(BUILD_DIR)/$(TARGET)
