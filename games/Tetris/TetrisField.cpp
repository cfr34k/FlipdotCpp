#include <games/Tetris/TetrisField.h>
#include <games/Tetris/TetrisBlock.h>
#include <FlipdotFramebuffer.h>

void TetrisField::clear()
{
	for (int i=0; i<FIELD_HEIGHT; i++)
	{
		_data[i] = 0;
	}
}

void TetrisField::setPoint(int fieldX, int fieldY, bool value)
{
	if ((fieldX<0) || (fieldX>=FIELD_WIDTH)) { return; }
	if ((fieldY<0) || (fieldY>=FIELD_HEIGHT)) { return; }
	uint16_t bitmask = (1<<fieldX);
	if (value) {
		_data[fieldY] |= bitmask;
	} else {
		_data[fieldY] &= ~bitmask;
	}
}

bool TetrisField::getPoint(int fieldX, int fieldY) const
{
	if (fieldY<0) { return false; }
	if (fieldY>=FIELD_HEIGHT) { return true; }
	if ( (fieldX<0) || (fieldX >= FIELD_WIDTH) ) { return true; }
	return (_data[fieldY] & (1<<fieldX)) != 0;
}

bool TetrisField::getPixel(int x, int y) const
{
	int fieldX = x / POINT_WIDTH;
	int fieldY = y / POINT_HEIGHT;
	return getPoint(fieldX, fieldY);
}

void TetrisField::draw(FlipdotFramebuffer& fb, int x, int y, bool doInvert) const
{
	for (int fieldY=0; fieldY<FIELD_HEIGHT; fieldY++)
	{
		bool invertThisRow = doInvert ^ (_invertFullRows && isRowFull(fieldY));

		for (int fieldX=0; fieldX<FIELD_WIDTH; fieldX++)
		{
			bool value = getPoint(fieldX, fieldY) ^ invertThisRow;
			drawPoint(fb, x, y, fieldX, fieldY, value);
		}
	}
}

void TetrisField::drawPoint(FlipdotFramebuffer& fb, int x, int y, int fieldX, int fieldY, bool value) const
{
	auto px = x + (fieldX*POINT_WIDTH);
	auto py = y + fieldY*POINT_WIDTH;
	fb.drawRect(px, py, POINT_WIDTH, POINT_HEIGHT, value);
}

bool TetrisField::isRowFull(int row) const
{
	if ( (row<0) || (row >= FIELD_HEIGHT) ) {
		return false;
	} else {
		return (_data[row] & FULL_ROW_MASK) == FULL_ROW_MASK;
	}
}

void TetrisField::deleteRow(int row)
{
	for (int y=row; y>0; y--)
	{
		_data[y] = _data[y-1];
	}
	_data[0] = 0;
}

bool TetrisField::hasFullRows() const
{
	for (int i=0; i<FIELD_HEIGHT; i++)
	{
		if (isRowFull(i))
		{
			return true;
		}
	}
	return false;
}

int TetrisField::deleteFullRows()
{
	int i=FIELD_HEIGHT-1;
	int deletedRows = 0;

	// TODO simplify loop
	while (i>0)
	{
		if (isRowFull(i)) {
			deleteRow(i);
			deletedRows++;
		} else {
			i--;
		}
	};

	return deletedRows;
}

void TetrisField::setInvertFullRows(bool doInvert)
{
	_invertFullRows = doInvert;
}
