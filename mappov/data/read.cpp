#include "read.h"
#include <gdal/gdal_priv.h>


// Read dataset at path and handle errors.
Dataset * Dataset::ReadDataset(std::string p)
{
	auto load = GDALOpen(p.c_str(), GA_ReadOnly);
	if (load == NULL) throw std::invalid_argument(p.append(" is invalid."));
	return (Dataset *) load;
}


Dataset * Dataset::SetTSize(uint16_t t_size)
{
	t_size = t_size;
	return this;
}


/* Datatype containing x, y offset coordinates. */
typedef struct _t_coords { uint16_t x; uint16_t y; } t_coords;

/* Return the pxl coordinates of a tile. */
t_coords Dataset::tile_coords(uint16_t index)
{
	t_coords offsets {};

	/* X offset is i'th tile of row times tile size.
	  (Reset if edge passed) */
	offsets.x = index % (GetRasterXSize() / t_size) * t_size;

	/* Y offset is i'th tile of column times tile size.
	  (Increment if edge passed) */
	offsets.y = index / (GetRasterXSize() / t_size) * t_size;

	return offsets;
}