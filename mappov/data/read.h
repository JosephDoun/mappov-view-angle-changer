# ifndef __READ
# define __READ
# include <gdal/gdal_priv.h>


struct _t_coords;
typedef _t_coords t_coords;


struct Dataset: public GDALDataset
{
	private:
	uint16_t t_size;
	t_coords tile_coords(uint16_t);

	public:
	/* Tile size setter function. */
	Dataset * SetTSize(uint16_t);

	/* Read a raster from file. */
	static Dataset * ReadDataset(std::string /* File path. */ p);

};


# endif