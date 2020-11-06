IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

_DEPS = CurrentConditionsDisplay.hpp DisplayElement.hpp \
	ForecastDisplay.hpp HeatIndexDisplay.hpp Observer.hpp \
	StatisticsDisplay.hpp Subject.hpp Utilities.hpp WeatherData.hpp
	
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = WeatherStation.o CurrentConditionsDisplay.o \
	DisplayElement.o ForecastDisplay.o HeatIndexDisplay.o \
	Observer.o StatisticsDisplay.o Subject.o Utilities.o WeatherData.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
