
struct wav_hdr {
  unsigned int   magic;
  unsigned int   length;
  unsigned int   chunk_type;
  unsigned int   chunk_format;
  unsigned int   chunk_length;
  unsigned short format;
  unsigned short channels;
  unsigned int   sample_rate;
  unsigned int   bytes_per_second;
  unsigned short sample_size;
  unsigned short precision;
  unsigned int   chunk_data;
  unsigned int   data_length;
};
