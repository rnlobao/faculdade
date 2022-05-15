#include "Model.h"

using namespace std;

auto Model::beginSystems() 
{
    return this->systems.begin();
}
auto Model::endSystems() 
{
    return this->systems.end();
}
auto Model::beginFlows() 
{
    return this->flows.begin();
}
auto Model::endFlows() 
{
    return this->flows.end();
}

void Model::execute(double start = 0.0, double final = 0.0, double increment = 1.0)
{
    vector<double> results;
    int count = 0;
    for (double k = start; k < final; k += increment)
    {
        for (Flow *item : flows)
        {
            double result = item->execute();
            results.push_back(result);
        }

        count = 0;
        for (Flow *item : flows)
        {
            System *origin = item->getSource();
            origin->setValue(origin->getValue() - results[count]);
            System *destiny = item->getTarget();
            destiny->setValue(destiny->getValue() + results[count]);
            count++;
        }

        for (auto i = beginFlows(); i != endFlows(); ++i)
        {
            results.pop_back();
        }
        time += increment;
    }
}

void Model::add(System *sys)
{
    this->systems.insert(endSystems(), sys);
}

void Model::add(Flow *flow)
{
    this->flows.insert(endFlows(), flow);
}

void Model::remove(System *sys)
{
    auto i = beginSystems();
    for (System *item : systems)
    {
        if (sys == item)
        {
            systems.erase(i);
            break;
        }
        ++i;
    }
}

void Model::remove(Flow *flow)
{
    auto i = beginFlows();
    for (Flow *item : flows)
    {
        if (flow == item)
        {
            flows.erase(i);
            break;
        }
        ++i;
    }
}

void Model::setName(string modelName)
{
    this->name = modelName;
}

string Model::getName() 
{
    return this->name;
}

void Model::setTime(double currentTime)
{
    this->time = currentTime;
}

double Model::getTime() 
{
    return this->time;
}

void Model::incrementTime(double increment)
{
    this->time += increment;
}

Model::Model(const Model &model)
{
    name = model.name;
    time = model.time;
    systems = model.systems;
    flows = model.flows;
}

Model& Model::operator=(const Model &model)
{
    if (this == &model)
    {
        return *this;
    }
    name = model.name;
    time = model.time;
    systems = model.systems;
    flows = model.flows;
    return *this;
}