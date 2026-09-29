# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2

# Executable names
CLEAN_EXE = clean_text
FILTER_EXE = filter_duplicates
UPDATE_EXE = update_stored

# Source files
CLEAN_SRC = clean_text.cpp
FILTER_SRC = filter_duplicates.cpp
UPDATE_SRC = update_stored.cpp

# Default target
all: build run

# Step 1: Build all executables
build: $(CLEAN_EXE) $(FILTER_EXE) $(UPDATE_EXE)

$(CLEAN_EXE): $(CLEAN_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(FILTER_EXE): $(FILTER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(UPDATE_EXE): $(UPDATE_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Step 2: Run the full process
run:
	@echo "🔹 Step 1: Cleaning text..."
	./$(CLEAN_EXE)
	@echo "🔹 Step 2: Removing duplicates..."
	./$(FILTER_EXE)
	@echo "🔹 Step 3: Updating stored.txt..."
	./$(UPDATE_EXE)
	@echo "✅ All steps complete!"

# Clean build files
clean:
	rm -f $(CLEAN_EXE) $(FILTER_EXE) $(UPDATE_EXE)

