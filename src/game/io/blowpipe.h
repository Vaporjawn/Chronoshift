/**
 * @file
 *
 * @author CCHyper
 * @author OmniBlade
 *
 * @brief Pipe stream class implementation writing data processed with the blowfish algorithm.
 *
 * @copyright Chronoshift is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#ifndef BLOWPIPE_H
#define BLOWPIPE_H

#include "blowfish.h"
#include "pipe.h"

class BlowPipe : public Pipe
{
public:
    BlowPipe(PipeControl mode = PIPE_ENCRYPT) : m_BlowFish(nullptr), m_Carryover(0), m_Mode(mode) {}
    virtual ~BlowPipe();

    virtual int Flush() override;
    virtual int Put(const void *buffer, int length) override;

    void Key(void *key, int key_size);

private:
    BlowfishEngine *m_BlowFish;
    char m_CurrentBlock[BF_BLOCKSIZE];
    int m_Carryover;
    PipeControl m_Mode;
};

#endif // BLOWPIPE_H
