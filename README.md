# CSV-Parser

#### Build a CSV parser that reads a file of IMU sensor readings, parses each line, stores the data in a dynamic array (or linked list), and provides basic query capabilities.

## Input File Format
#### timestamp,accel_x,accel_y,accel_z,gyro_x,gyro_y,gyro_z

## API
#### IMUReading* parse_csv(const char* filename, size_t* num_readings);
###### Parse a CSV file and return an array of IMUReading structs. Returns: Pointer to dynamically allocated array, or NULL on error.
#### The caller must free the returned pointer.

### void free_readings(IMUReading* readings);
#### Free an array of IMUReading structs

### IMUReading* filter_by_time(const IMUReading* readings, size_t num_readings,long start_time, long end_time, size_t* result_count);
###### Find all readings within a time range (inclusive). Returns: New dynamically allocated array of readings. The caller must free the returned pointer.

### IMUReading* find_max_acceleration(const IMUReading* readings, size_t num_readings);
###### Find the reading with the highest acceleration magnitude

### void average_acceleration(const IMUReading* readings, size_t num_readings, float* avg_x, float* avg_y, float* avg_z);
###### Calculate the average acceleration for each axis


### void print_reading(const IMUReading* reading);
### void print_readings(const IMUReading* readings, size_t num_readings, const char* label);
