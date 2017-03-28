#pragma once

#include "search/result.hpp"
#include "search/search_quality/sample.hpp"

#include <cstddef>
#include <string>
#include <vector>

class Edits;
class Model;

class View
{
public:
  virtual ~View() = default;

  void SetModel(Model & model) { m_model = &model; }

  virtual void SetSamples(std::vector<search::Sample> const & samples) = 0;
  virtual void ShowSample(size_t index, search::Sample const & sample, bool hasEdits) = 0;
  virtual void ShowResults(search::Results::Iter begin, search::Results::Iter end) = 0;

  virtual void OnSampleChanged(size_t index, bool hasEdits) = 0;
  virtual void EnableSampleEditing(size_t index, Edits & edits) = 0;
  virtual void OnSamplesChanged(bool hasEdits) = 0;

  virtual void ShowError(std::string const & msg) = 0;

protected:
  Model * m_model = nullptr;
};
